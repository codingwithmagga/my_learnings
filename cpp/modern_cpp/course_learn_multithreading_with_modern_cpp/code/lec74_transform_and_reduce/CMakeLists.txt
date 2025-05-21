cmake_minimum_required(VERSION 3.16)

project(lec74_transform_and_reduce LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lec74_transform_and_reduce main.cpp)

include(GNUInstallDirs)
install(TARGETS lec74_transform_and_reduce
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
