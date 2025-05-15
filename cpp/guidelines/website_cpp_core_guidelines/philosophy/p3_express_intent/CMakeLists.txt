cmake_minimum_required(VERSION 3.16)

project(p3_express_intent LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(p3_express_intent main.cpp)

target_link_libraries(p3_express_intent PRIVATE Microsoft.GSL::GSL)
