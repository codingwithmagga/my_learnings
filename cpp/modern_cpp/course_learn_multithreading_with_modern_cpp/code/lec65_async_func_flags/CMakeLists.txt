cmake_minimum_required(VERSION 3.16)

project(lec65_async_func_flags LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lec65_async_func_flags main.cpp)

include(GNUInstallDirs)
install(TARGETS lec65_async_func_flags
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
