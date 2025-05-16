cmake_minimum_required(VERSION 3.16)

project(p4_type_safe_program LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(p4_type_safe_program main.cpp)

target_link_libraries(p4_type_safe_program PRIVATE Microsoft.GSL::GSL)
