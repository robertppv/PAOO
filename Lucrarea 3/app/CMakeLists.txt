cmake_minimum_required(VERSION 3.2)

project(app)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(app_files src/main.cpp)

add_executable(${PROJECT_NAME} ${app_files})

target_link_libraries(${PROJECT_NAME} PRIVATE buffer)
