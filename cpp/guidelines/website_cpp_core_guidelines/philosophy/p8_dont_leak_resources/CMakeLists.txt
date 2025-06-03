cmake_minimum_required(VERSION 3.16)

project(p8_dont_leak_resources LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(p8_dont_leak_resources main.cpp)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/example.txt
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
