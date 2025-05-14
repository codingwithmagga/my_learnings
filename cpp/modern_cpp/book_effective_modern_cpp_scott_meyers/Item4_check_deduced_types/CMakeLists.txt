cmake_minimum_required(VERSION 3.16)

project(item4_check_deduced_types LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(item4_check_deduced_types main.cpp)

target_link_libraries(item4_check_deduced_types Boost::type_index)
