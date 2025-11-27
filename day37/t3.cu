#include <iostream>
#include <cuda_runtime.h>

const int N = 512;  // 定义数组大小为 512

// CUDA 内核函数：用于在 GPU 上执行的代码
__global__ void vectorAddShared(int* a, int* b, int* c) {
    __shared__ int shared_a[N];  // 在共享内存中声明 a 数组
    __shared__ int shared_b[N];  // 在共享内存中声明 b 数组

    int index = threadIdx.x;  // 获取每个线程的索引

    // 将全局内存中的数据复制到共享内存
    shared_a[index] = a[index];
    shared_b[index] = b[index];

    __syncthreads();  // 保证所有线程都完成了数据复制

    // 执行向量加法
    c[index] = shared_a[index] + shared_b[index];
}

int main() {
    int a[N], b[N], c[N];  // 在 Host (CPU) 上定义三个数组
    int *d_a, *d_b, *d_c;  // 定义指向 Device (GPU) 上数据的指针

    // 在 GPU 上分配内存
    cudaMalloc((void**)&d_a, N * sizeof(int));  // 分配 a 数组的内存
    cudaMalloc((void**)&d_b, N * sizeof(int));  // 分配 b 数组的内存
    cudaMalloc((void**)&d_c, N * sizeof(int));  // 分配 c 数组的内存

    // 初始化 Host 上的数组
    for (int i = 0; i < N; i++) {
        a[i] = i;  // 初始化 a 数组
        b[i] = i * 2;  // 初始化 b 数组
    }

    // 将数据从 Host 复制到 Device
    cudaMemcpy(d_a, a, N * sizeof(int), cudaMemcpyHostToDevice);  // 复制 a 数组到 GPU
    cudaMemcpy(d_b, b, N * sizeof(int), cudaMemcpyHostToDevice);  // 复制 b 数组到 GPU

    // 启动 CUDA 内核
    vectorAddShared<<<1, N>>>(d_a, d_b, d_c);

    // 将结果从 Device 复制回 Host
    cudaMemcpy(c, d_c, N * sizeof(int), cudaMemcpyDeviceToHost);

    // 输出结果
    for (int i = 0; i < N; i++) {
        std::cout << a[i] << " + " << b[i] << " = " << c[i] << std::endl;
    }

    // 释放 GPU 上的内存
    cudaFree(d_a);
    cudaFree(d_b);
    cudaFree(d_c);

    return 0;
}