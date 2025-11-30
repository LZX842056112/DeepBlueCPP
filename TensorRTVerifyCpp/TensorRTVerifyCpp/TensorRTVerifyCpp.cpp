#include <iostream>
#include <NvInfer.h>
#include <NvInferRuntime.h>

using namespace nvinfer1;

// 简单的 Logger：只打印 Info 及以上级别日志
class SimpleLogger : public ILogger {
public:
    void log(Severity severity, const char* msg) noexcept override {
        // 只打印 Info 及以上（忽略 Verbose）
        if (severity <= Severity::kINFO) {
            std::cout << "[TensorRT] " << msg << std::endl;
        }
    }
};

int main() {
    SimpleLogger logger;

    std::cout << "Creating TensorRT builder..." << std::endl;
    IBuilder* builder = createInferBuilder(logger);
    if (!builder) {
        std::cerr << "Failed to create TensorRT builder. Check installation." << std::endl;
        return -1;
    }

    // 显式 batch 模式
    uint32_t explicitBatch = 1U << static_cast<uint32_t>(NetworkDefinitionCreationFlag::kEXPLICIT_BATCH);
    INetworkDefinition* network = builder->createNetworkV2(explicitBatch);
    if (!network) {
        std::cerr << "Failed to create network definition." << std::endl;
        delete builder;
        return -1;
    }

    // 创建一个输入张量，形状 (1,1,1)
    ITensor* input = network->addInput("input", DataType::kFLOAT, Dims3{ 1, 1, 1 });
    if (!input) {
        std::cerr << "Failed to add input tensor." << std::endl;
        delete network;
        delete builder;
        return -1;
    }

    // Identity 层：输出 = 输入
    ILayer* identityLayer = network->addIdentity(*input);
    if (!identityLayer) {
        std::cerr << "Failed to add identity layer." << std::endl;
        delete network;
        delete builder;
        return -1;
    }
    identityLayer->setName("identity_layer");

    ITensor* output = identityLayer->getOutput(0);
    output->setName("output");
    network->markOutput(*output);

    // 创建 BuilderConfig
    IBuilderConfig* config = builder->createBuilderConfig();
    if (!config) {
        std::cerr << "Failed to create builder config." << std::endl;
        delete network;
        delete builder;
        return -1;
    }

    // TensorRT 10.x 使用新的内存池设置方法
    config->setMemoryPoolLimit(MemoryPoolType::kWORKSPACE, 1 << 20); // 1MB

    std::cout << "Building TensorRT engine..." << std::endl;
    IHostMemory* serializedEngine = builder->buildSerializedNetwork(*network, *config);
    if (!serializedEngine) {
        std::cerr << "Failed to build serialized engine. Check CUDA/cuDNN/TensorRT." << std::endl;
        delete config;
        delete network;
        delete builder;
        return -1;
    }

    std::cout << "Engine serialized successfully. Size = "
        << serializedEngine->size() << " bytes" << std::endl;

    // 反序列化引擎 - TensorRT 10.x 使用新的 API
    IRuntime* runtime = createInferRuntime(logger);
    if (!runtime) {
        std::cerr << "Failed to create runtime." << std::endl;
        delete serializedEngine;
        delete config;
        delete network;
        delete builder;
        return -1;
    }

    ICudaEngine* engine = runtime->deserializeCudaEngine(serializedEngine->data(), serializedEngine->size());
    if (!engine) {
        std::cerr << "Failed to deserialize engine." << std::endl;
        delete runtime;
        delete serializedEngine;
        delete config;
        delete network;
        delete builder;
        return -1;
    }

    std::cout << "Engine deserialized successfully." << std::endl;

    // TensorRT 10.x 使用新的张量 API
    std::cout << "Number of I/O tensors: " << engine->getNbIOTensors() << std::endl;

    for (int i = 0; i < engine->getNbIOTensors(); ++i) {
        const char* tensorName = engine->getIOTensorName(i);
        TensorIOMode mode = engine->getTensorIOMode(tensorName);
        Dims dims = engine->getTensorShape(tensorName);
        DataType dtype = engine->getTensorDataType(tensorName);

        std::string modeStr = (mode == TensorIOMode::kINPUT) ? "INPUT" : "OUTPUT";
        std::cout << "  Tensor " << i
            << " name=" << tensorName
            << ", mode=" << modeStr
            << ", dims=(";
        for (int d = 0; d < dims.nbDims; ++d) {
            std::cout << dims.d[d];
            if (d + 1 < dims.nbDims) std::cout << ",";
        }
        std::cout << "), dtype=" << static_cast<int>(dtype) << std::endl;
    }

    // 释放资源 - TensorRT 10.x 使用 delete 而不是 destroy()
    delete engine;
    delete runtime;
    delete serializedEngine;
    delete config;
    delete network;
    delete builder;

    std::cout << "TensorRT C++ verification finished successfully." << std::endl;
    return 0;
}