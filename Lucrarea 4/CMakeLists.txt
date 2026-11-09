cmake_minimum_required(VERSION 3.10)

project(lab4)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


add_executable(effective_cpp
    main.cpp
    src/resource.cpp)

target_include_directories(effective_cpp PRIVATE include)
