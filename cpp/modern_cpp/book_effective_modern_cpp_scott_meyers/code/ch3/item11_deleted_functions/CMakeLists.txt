cmake_minimum_required(VERSION 3.16)

project(item11_deleted_functions LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(item11_deleted_functions main.cpp)

target_link_libraries(item11_deleted_functions Boost::type_index)
