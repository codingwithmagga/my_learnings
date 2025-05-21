cmake_minimum_required(VERSION 3.16)

project(lec54_future_multiple_consumers LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lec54_future_multiple_consumers main.cpp)

include(GNUInstallDirs)
install(TARGETS lec54_future_multiple_consumers
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
