cmake_minimum_required(VERSION 3.16)

project(lec72_exceptions_parallel LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lec72_exceptions_parallel main.cpp)

include(GNUInstallDirs)
install(TARGETS lec72_exceptions_parallel
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
