cmake_minimum_required(VERSION 3.16)

project(website_cpp_core_guidelines LANGUAGES CXX)

include(FetchContent)

FetchContent_Declare(GSL
    GIT_REPOSITORY "https://github.com/microsoft/GSL"
    GIT_TAG "v4.2.0"
    GIT_SHALLOW ON
)

FetchContent_MakeAvailable(GSL)

add_subdirectory(philosophy)