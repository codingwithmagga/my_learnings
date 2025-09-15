cmake_minimum_required(VERSION 3.16)

project(lec86_threadpool_multiple_queues LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lec86_threadpool_multiple_queues main.cpp)

include(GNUInstallDirs)
install(TARGETS lec86_threadpool_multiple_queues
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
