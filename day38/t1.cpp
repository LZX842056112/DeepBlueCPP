#define ORT_API_VERSION 17
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <opencv2/opencv.hpp>
#include <onnxruntime_cxx_api.h>


std::vector<float> preprocess(const cv::Mat& img) {
    cv::Mat processed;

    cv::resize(img, processed, cv::Size(28, 28));

    processed.convertTo(processed, CV_32F, 1.0 / 255.0);

    // 这里的数学运算在 CPU 上对 28x28 矩阵极快，无需 CUDA 核函数
    processed = (processed - 0.1307) / 0.3081;

    // 4. Flatten (展开为一维向量)
    std::vector<float> input_tensor_values;
    if (processed.isContinuous()) {
        input_tensor_values.assign((float*)processed.datastart, (float*)processed.dataend);
    } else {
        for (int i = 0; i < processed.rows; ++i)
            input_tensor_values.insert(input_tensor_values.end(), processed.ptr<float>(i), processed.ptr<float>(i) + processed.cols);
    }
    return input_tensor_values;
}

int main() {
    std::string model_path = "mnist_cnn.onnx";
    std::string image_path = "test_digit.png";

    // --- 关键修改 1: 初始化 ONNX 环境 ---
    Ort::Env env(ORT_LOGGING_LEVEL_WARNING, "MnistCuda");
    //Ort::Env env(ORT_LOGGING_LEVEL_WARNING, "MnistCuda", Ort::Env::GetAvailableProviders(), 0, ORT_API_VERSION_17);
    Ort::SessionOptions session_options;

    // 这段代码告诉 ONNX Runtime 优先使用 GPU 进行计算
    try {
        OrtCUDAProviderOptions cuda_options;
        cuda_options.device_id = 0; // 使用 0 号 GPU
        // 显存溢出策略等可以根据需要配置
        // cuda_options.arena_extend_strategy = 0;

        session_options.AppendExecutionProvider_CUDA(cuda_options);
        std::cout << "CUDA Execution Provider enabled successfully." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Failed to enable CUDA provider: " << e.what() << std::endl;
        std::cerr << "Falling back to CPU." << std::endl;
    }

    // 这个时候此时模型会被加载到 GPU 显存
    // Ort::Session session(env, model_path.c_str(), session_options);
    Ort::Session session(env, L"mnist_cnn.onnx", session_options);

    // 读取图片 (CPU)
    cv::Mat img = cv::imread(image_path, cv::IMREAD_GRAYSCALE);
    if (img.empty()) {
        std::cerr << "Error: Could not read image from " << image_path << std::endl;
        return -1;
    }

    // 预处理 (CPU)
    // 此时数据在 CPU 内存中
    std::vector<float> input_tensor_values = preprocess(img);

    std::vector<int64_t> input_shape = {1, 1, 28, 28};
    size_t input_tensor_size = 28 * 28;

    // 注意：这里我们依然使用 Cpu 内存创建 Tensor，ONNX Runtime 在运行 Run() 时
    // 会自动处理 CPU -> GPU 的数据拷贝 (Host to Device Copy)。
    // 如果追求极致性能，需使用 Ort::MemoryInfo::CreateCuda 并使用 cudaMalloc 预分配显存，
    auto memory_info = Ort::MemoryInfo::CreateCpu(OrtArenaAllocator, OrtMemTypeDefault);

    Ort::Value input_tensor = Ort::Value::CreateTensor<float>(
        memory_info,
        input_tensor_values.data(),
        input_tensor_size,
        input_shape.data(),
        input_shape.size()
    );

    const char* input_names[] = {"input"};
    const char* output_names[] = {"output"};

    std::cout << "Running Inference on GPU..." << std::endl;

    // 执行推理 (Compute on GPU)
    auto output_tensors = session.Run(
        Ort::RunOptions{nullptr},
        input_names,
        &input_tensor,
        1,
        output_names,
        1
    );

    // 获取结果，返回到 CPU
    float* floatarr = output_tensors[0].GetTensorMutableData<float>();

    auto max_it = std::max_element(floatarr, floatarr + 10);
    int prediction = std::distance(floatarr, max_it);
    float confidence = *max_it;

    std::cout << "-----------------------" << std::endl;
    std::cout << "Prediction Result: " << prediction << std::endl;
    std::cout << "Raw Logit Value:   " << confidence << std::endl;
    std::cout << "-----------------------" << std::endl;

    return 0;
}