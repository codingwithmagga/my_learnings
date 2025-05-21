cmake_minimum_required(VERSION 3.16)

project(lec32_mutex_timeouts LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lec32_mutex_timeouts main.cpp)

include(GNUInstallDirs)
install(TARGETS lec32_mutex_timeouts
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
