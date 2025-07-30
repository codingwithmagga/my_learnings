cmake_minimum_required(VERSION 3.16)

project(item22_pimpl_idiom LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(item22_pimpl_idiom main.cpp
    widget.h widget.cpp
    gadget.h)
