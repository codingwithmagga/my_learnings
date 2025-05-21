cmake_minimum_required(VERSION 3.16)

project(lec82_concurrent_queue LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lec82_concurrent_queue main.cpp)

include(GNUInstallDirs)
install(TARGETS lec82_concurrent_queue
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
