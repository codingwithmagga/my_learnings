cmake_minimum_required(VERSION 3.16)

project(lec14_starting_threads LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lec14_starting_threads main.cpp)

include(GNUInstallDirs)
install(TARGETS lec14_starting_threads
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
