cmake_minimum_required(VERSION 3.16)

project(item14_use_noexcept LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(item14_use_noexcept main.cpp)
