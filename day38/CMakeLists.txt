cmake_minimum_required(VERSION 3.10)
project(MnistCpp)

set(CMAKE_CXX_STANDARD 17)

# 设置 OpenCV 路径 - 修正为正确的路径
set(OpenCV_DIR "C:/MySoftware/opencv/build")
find_package(OpenCV REQUIRED)

if(OpenCV_FOUND)
    message(STATUS "Found OpenCV ${OpenCV_VERSION}")
    message(STATUS "OpenCV libraries: ${OpenCV_LIBS}")
    message(STATUS "OpenCV include dir: ${OpenCV_INCLUDE_DIRS}")
else()
    message(FATAL_ERROR "OpenCV not found")
endif()

# ONNX Runtime 配置 - 使用正确的路径
set(ONNXRUNTIME_ROOT "D:/Projects/DeepBule/C++Project/onnxruntime")

find_path(ONNXRUNTIME_INCLUDE_DIR
        NAMES onnxruntime_cxx_api.h
        PATHS ${ONNXRUNTIME_ROOT}/include
        NO_DEFAULT_PATH
)

find_library(ONNXRUNTIME_LIB
        NAMES onnxruntime
        PATHS ${ONNXRUNTIME_ROOT}/lib
        NO_DEFAULT_PATH
)

if(NOT ONNXRUNTIME_INCLUDE_DIR OR NOT ONNXRUNTIME_LIB)
    message(FATAL_ERROR "未找到 ONNX Runtime！请确认路径设置。")
else()
    message(STATUS "Found ONNX Runtime Include: ${ONNXRUNTIME_INCLUDE_DIR}")
    message(STATUS "Found ONNX Runtime Lib: ${ONNXRUNTIME_LIB}")
endif()

add_executable(mnist_demo t1.cpp)

target_include_directories(mnist_demo PRIVATE
        ${OpenCV_INCLUDE_DIRS}
        ${ONNXRUNTIME_INCLUDE_DIR}
)

target_link_libraries(mnist_demo PRIVATE
        ${OpenCV_LIBS}
        ${ONNXRUNTIME_LIB}
)