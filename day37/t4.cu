#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>
#include <cuda_runtime.h>

// CUDA kernel: convert image to CHW format tensor
__global__ void convert_image_to_tensor(const float3* image, float* tensor, int width, int height) {
    int w = threadIdx.x + blockIdx.x * blockDim.x;
    int h = threadIdx.y + blockIdx.y * blockDim.y;
    int c = blockIdx.z;

    if (w < width && h < height && c < 3) {
        int image_idx = h * width + w;
        float3 pixel = image[image_idx];
        float val = (c == 0) ? pixel.x : (c == 1) ? pixel.y : pixel.z;

        int tensor_idx = c * height * width + h * width + w;
        tensor[tensor_idx] = val;
    }
}

int main() {
    // Load image
    cv::Mat image = cv::imread("image.jpg", cv::IMREAD_COLOR);
    if (image.empty()) {
        std::cerr << "Failed to load image." << std::endl;
        return -1;
    }

    // Convert to float32 and normalize
    image.convertTo(image, CV_32FC3, 1.0 / 255.0);

    int width = image.cols;
    int height = image.rows;

    // Host pointers
    std::vector<float> host_tensor(3 * height * width);
    float3* host_image = new float3[height * width];

    // Convert cv::Vec3f to float3
    for (int i = 0; i < height * width; ++i) {
        cv::Vec3f pix = image.at<cv::Vec3f>(i);
        host_image[i] = make_float3(pix[0], pix[1], pix[2]);
    }

    // Device pointers
    float3* dev_image;
    float* dev_tensor;

    cudaMalloc(&dev_image, height * width * sizeof(float3));
    cudaMalloc(&dev_tensor, 3 * height * width * sizeof(float));

    cudaMemcpy(dev_image, host_image, height * width * sizeof(float3), cudaMemcpyHostToDevice);

    // Launch kernel
    dim3 block(16, 16);
    dim3 grid((width + block.x - 1) / block.x,
              (height + block.y - 1) / block.y,
              3);

    convert_image_to_tensor<<<grid, block>>>(dev_image, dev_tensor, width, height);
    cudaDeviceSynchronize();

    cudaMemcpy(host_tensor.data(), dev_tensor, 3 * height * width * sizeof(float), cudaMemcpyDeviceToHost);

    // Clean up
    cudaFree(dev_image);
    cudaFree(dev_tensor);
    delete[] host_image;

    std::cout << "Image converted to tensor (CHW layout). First pixel RGB: "
              << host_tensor[0] << ", " << host_tensor[height * width]
              << ", " << host_tensor[2 * height * width] << std::endl;

    return 0;
}
