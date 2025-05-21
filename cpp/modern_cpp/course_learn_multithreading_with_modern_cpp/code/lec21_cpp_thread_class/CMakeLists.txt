cmake_minimum_required(VERSION 3.16)

project(lec21_cpp_thread_class LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lec21_cpp_thread_class main.cpp)

include(GNUInstallDirs)
install(TARGETS lec21_cpp_thread_class
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
