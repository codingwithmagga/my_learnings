cmake_minimum_required(VERSION 3.16)

project(helper_lib
    VERSION 1.0.0
    LANGUAGES CXX
)

add_library(${PROJECT_NAME} INTERFACE helper_lib.hpp)

target_include_directories(
    ${PROJECT_NAME}
    INTERFACE
    .
)
