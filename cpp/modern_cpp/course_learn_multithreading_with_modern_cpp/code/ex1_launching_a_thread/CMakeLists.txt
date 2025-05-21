cmake_minimum_required(VERSION 3.16)

project(ex1_launchinf_a_thread LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ex1_launchinf_a_thread main.cpp)

include(GNUInstallDirs)
install(TARGETS ex1_launchinf_a_thread
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
