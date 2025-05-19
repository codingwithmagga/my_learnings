cmake_minimum_required(VERSION 3.16)

project(p5_compile_time_checking LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(p5_compile_time_checking main.cpp)
