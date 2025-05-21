cmake_minimum_required(VERSION 3.16)

project(lec36_thread_local LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lec36_thread_local main.cpp)

include(GNUInstallDirs)
install(TARGETS lec36_thread_local
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
