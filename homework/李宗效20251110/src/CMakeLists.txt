cmake_minimum_required(VERSION 3.10)

project(src)

add_executable(${PROJECT_NAME} calculator.cpp)

target_link_libraries(${PROJECT_NAME} lib)