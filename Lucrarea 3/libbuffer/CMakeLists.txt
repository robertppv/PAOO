cmake_minimum_required(VERSION 3.2)

project(buffer)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


set(buffer_files src/Buffer.cpp inc/Buffer.hpp)

add_library(${PROJECT_NAME} STATIC ${buffer_files})

target_include_directories(${PROJECT_NAME}
    PRIVATE   src inc
    INTERFACE inc)
