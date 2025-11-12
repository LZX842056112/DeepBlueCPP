cmake_minimum_required(VERSION 3.10)

project(cmake_large)

add_subdirectory(add_module)
add_subdirectory(sub_module)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} add_module sub_module)