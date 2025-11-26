#include <cstdio>
__global__ void helloFromGPU() {
    printf("Hello from GPU\n");
}
int main() {
    printf("Hello from CPU\n");
    helloFromGPU<<<1,1>>>();
    cudaDeviceSynchronize();
    return 0;
}