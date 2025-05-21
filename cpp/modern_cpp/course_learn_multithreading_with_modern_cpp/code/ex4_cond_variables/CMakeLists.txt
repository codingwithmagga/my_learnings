cmake_minimum_required(VERSION 3.16)

project(ex4_cond_variables LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ex4_cond_variables main.cpp)

include(GNUInstallDirs)
install(TARGETS ex4_cond_variables
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
