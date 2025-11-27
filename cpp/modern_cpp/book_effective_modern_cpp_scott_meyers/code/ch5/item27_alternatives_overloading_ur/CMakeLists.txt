cmake_minimum_required(VERSION 3.16)

project(item27_alternatives_overloading_ur LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(item27_alternatives_overloading_ur main.cpp)

target_link_libraries(
    item27_alternatives_overloading_ur
    PUBLIC
        helper_lib
)
