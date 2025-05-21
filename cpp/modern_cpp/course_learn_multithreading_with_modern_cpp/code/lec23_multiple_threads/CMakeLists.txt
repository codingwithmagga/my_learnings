cmake_minimum_required(VERSION 3.16)

project(lec23_multiple_threads LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lec23_multiple_threads main.cpp)

include(GNUInstallDirs)
install(TARGETS lec23_multiple_threads
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
