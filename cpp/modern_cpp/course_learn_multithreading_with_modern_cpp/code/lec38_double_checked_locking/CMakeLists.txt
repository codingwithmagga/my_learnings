cmake_minimum_required(VERSION 3.16)

project(lec38_double_checked_locking LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lec38_double_checked_locking main.cpp)

include(GNUInstallDirs)
install(TARGETS lec38_double_checked_locking
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
