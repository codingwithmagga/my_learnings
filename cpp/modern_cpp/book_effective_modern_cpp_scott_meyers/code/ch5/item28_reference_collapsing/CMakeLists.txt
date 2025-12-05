cmake_minimum_required(VERSION 3.16)

project(item28_reference_collapsing LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(item28_reference_collapsing main.cpp)

target_link_libraries(
    item28_reference_collapsing
    PUBLIC
        Boost::type_index
)
