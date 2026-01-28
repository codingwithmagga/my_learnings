cmake_minimum_required(VERSION 3.16)

project(item30_perfect_forwarding_pitfalls LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(item30_perfect_forwarding_pitfalls main.cpp)
