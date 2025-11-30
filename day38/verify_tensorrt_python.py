import tensorrt as trt

def main():
    # 1. 打印 TensorRT 版本
    print("TensorRT Python version:", trt.__version__)

    # 2. 创建 Logger
    logger = trt.Logger(trt.Logger.INFO)

    # 3. 创建 Builder
    builder = trt.Builder(logger)
    # 使用显式 batch 模式（TensorRT 8+ 推荐）
    EXPLICIT_BATCH = 1 << int(trt.NetworkDefinitionCreationFlag.EXPLICIT_BATCH)
    network = builder.create_network(EXPLICIT_BATCH)

    # 4. 定义一个简单网络：输入 -> Identity -> 输出
    input_tensor = network.add_input(
        name="input",
        dtype=trt.float32,
        shape=(1, 1, 1)  # NCHW 中的 CHW（N 由显式 batch 控制）
    )

    identity_layer = network.add_identity(input_tensor)
    identity_layer.name = "identity_layer"

    network.mark_output(identity_layer.get_output(0))

    # 5. 创建 BuilderConfig 并构建引擎
    config = builder.create_builder_config()
    # config.max_workspace_size = 1 << 20  # 1MB，示例用，足够这个小网络
    config.set_memory_pool_limit(trt.MemoryPoolType.WORKSPACE, 1 << 20)

    print("Building TensorRT engine...")
    serialized_engine = builder.build_serialized_network(network, config)
    if serialized_engine is None:
        print("Failed to build serialized engine. Please check CUDA/cuDNN/TensorRT installation.")
        return

    # 6. 使用 Runtime 反序列化引擎
    runtime = trt.Runtime(logger)
    engine = runtime.deserialize_cuda_engine(serialized_engine)

    if engine is None:
        print("Failed to deserialize engine.")
    else:
        print("Engine built and deserialized successfully.")
        # print("Number of bindings:", engine.num_bindings)
        # for i in range(engine.num_bindings):
        #     name = engine.get_binding_name(i)
        #     is_input = engine.binding_is_input(i)
        #     print(f"  Binding {i}: name={name}, is_input={is_input}, shape={engine.get_binding_shape(i)}")

        # TensorRT 10.x 使用新的 API 获取绑定信息
        print("Number of I/O tensors:", engine.num_io_tensors)

        # 获取所有张量名称
        tensor_names = [engine.get_tensor_name(i) for i in range(engine.num_io_tensors)]

        for i, name in enumerate(tensor_names):
            mode = engine.get_tensor_mode(name)
            shape = engine.get_tensor_shape(name)
            dtype = engine.get_tensor_dtype(name)

            mode_str = "INPUT" if mode == trt.TensorIOMode.INPUT else "OUTPUT"
            print(f"  Tensor {i}: name={name}, mode={mode_str}, shape={shape}, dtype={dtype}")

if __name__ == "__main__":
    main()