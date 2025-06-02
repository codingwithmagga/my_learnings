cmake_minimum_required(VERSION 3.16)

project(p6_run_time_checks LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(p6_run_time_checks main.cpp)

include(GNUInstallDirs)
install(TARGETS p6_run_time_checks
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
