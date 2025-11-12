cmake_minimum_required(VERSION 3.10)

project(sub_module)

add_library(${PROJECT_NAME} STATIC sub.cpp)