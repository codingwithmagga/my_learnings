cmake_minimum_required(VERSION 3.16)

project(item35_prefer_std_async LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(item35_prefer_std_async main.cpp)
