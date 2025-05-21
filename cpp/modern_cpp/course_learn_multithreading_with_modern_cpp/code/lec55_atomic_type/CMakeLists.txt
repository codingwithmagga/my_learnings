cmake_minimum_required(VERSION 3.16)

project(lec55_atomic_type LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lec55_atomic_type main.cpp)

include(GNUInstallDirs)
install(TARGETS lec55_atomic_type
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
