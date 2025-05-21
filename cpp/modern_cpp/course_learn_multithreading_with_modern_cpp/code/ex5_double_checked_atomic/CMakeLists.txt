cmake_minimum_required(VERSION 3.16)

project(ex5_double_checked_atomic LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ex5_double_checked_atomic main.cpp)

include(GNUInstallDirs)
install(TARGETS ex5_double_checked_atomic
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
