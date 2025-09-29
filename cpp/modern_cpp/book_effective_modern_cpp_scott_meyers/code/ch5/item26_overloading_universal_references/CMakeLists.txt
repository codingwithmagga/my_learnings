cmake_minimum_required(VERSION 3.16)

project(item26_overloading_universal_references LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(item26_overloading_universal_references main.cpp)

target_link_libraries(
    item26_overloading_universal_references
    PUBLIC
        helper_lib
)
