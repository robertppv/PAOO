cmake_minimum_required(VERSION 3.16)

project(lucrarea6)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

add_executable(effective_cpp
    src/main.cpp)

target_include_directories(effective_cpp PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include)

if(MSVC)
    target_compile_options(effective_cpp PRIVATE /W4)
else()
    target_compile_options(effective_cpp PRIVATE -Wall -Wextra -Wpedantic)
endif()
