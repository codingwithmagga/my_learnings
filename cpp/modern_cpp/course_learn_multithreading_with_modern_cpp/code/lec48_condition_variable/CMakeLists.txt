cmake_minimum_required(VERSION 3.16)

project(lec48_condition_variable LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lec48_condition_variable main.cpp)

include(GNUInstallDirs)
install(TARGETS lec48_condition_variable
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
