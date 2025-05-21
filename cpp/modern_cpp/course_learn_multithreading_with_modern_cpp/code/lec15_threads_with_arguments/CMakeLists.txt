cmake_minimum_required(VERSION 3.16)

project(lec15_threads_with_arguments LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lec15_threads_with_arguments main.cpp)

include(GNUInstallDirs)
install(TARGETS lec15_threads_with_arguments
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
