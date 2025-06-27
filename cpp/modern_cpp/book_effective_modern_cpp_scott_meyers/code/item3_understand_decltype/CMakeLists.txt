cmake_minimum_required(VERSION 3.16)

project(item3_understand_decltype LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(item3_understand_decltype main.cpp)

target_link_libraries(item3_understand_decltype Boost::type_index)
