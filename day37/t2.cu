#include <iostream>
#include <cuda_runtime.h>

const int N = 16;  // 定义矩阵大小为 16x16

// CUDA 内核函数：用于在 GPU 上执行的代码
__global__ void matrixAdd(int* a, int* b, int* c, int width) {
    int col = threadIdx.x + blockIdx.x * blockDim.x;  // 计算当前线程对应的列索引
    int row = threadIdx.y + blockIdx.y * blockDim.y;  // 计算当前线程对应的行索引

    int idx = row * width + col;  // 将 2D 索引转换为 1D 索引
    if (col < width && row < width) {  // 确保索引在矩阵范围内
        c[idx] = a[idx] + b[idx];  // 执行矩阵加法
    }
}

int main() {
    int a[N * N], b[N * N], c[N * N];  // 在 Host (CPU) 上定义三个矩阵
    int *d_a, *d_b, *d_c;  // 定义指向 Device (GPU) 上数据的指针

    // 在 GPU 上分配内存
    cudaMalloc((void**)&d_a, N * N * sizeof(int));  // 分配 a 矩阵的内存
    cudaMalloc((void**)&d_b, N * N * sizeof(int));  // 分配 b 矩阵的内存
    cudaMalloc((void**)&d_c, N * N * sizeof(int));  // 分配 c 矩阵的内存

    // 初始化 Host 上的矩阵
    for (int i = 0; i < N * N; i++) {
        a[i] = i;  // 初始化 a 矩阵
        b[i] = i * 2;  // 初始化 b 矩阵
    }

    // 将数据从 Host 复制到 Device
    cudaMemcpy(d_a, a, N * N * sizeof(int), cudaMemcpyHostToDevice);  // 复制 a 矩阵到 GPU
    cudaMemcpy(d_b, b, N * N * sizeof(int), cudaMemcpyHostToDevice);  // 复制 b 矩阵到 GPU

    // 定义线程块和网格的维度
    dim3 threadsPerBlock(4, 4);  // 每个块有 4x4 = 16 个线程
    dim3 numBlocks(N / threadsPerBlock.x, N / threadsPerBlock.y);  // 总共 4x4 = 16 个块

    // 启动 CUDA 内核
    matrixAdd<<<numBlocks, threadsPerBlock>>>(d_a, d_b, d_c, N);

    // 将结果从 Device 复制回 Host
    cudaMemcpy(c, d_c, N * N * sizeof(int), cudaMemcpyDeviceToHost);

    // 输出结果
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << c[i * N + j] << " ";
        }
        std::cout << std::endl;
    }

    // 释放 GPU 上的内存
    cudaFree(d_a);
    cudaFree(d_b);
    cudaFree(d_c);

    return 0;
}