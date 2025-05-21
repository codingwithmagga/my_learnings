cmake_minimum_required(VERSION 3.16)

project(lec64_async_func LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lec64_async_func main.cpp)

include(GNUInstallDirs)
install(TARGETS lec64_async_func
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
