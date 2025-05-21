cmake_minimum_required(VERSION 3.16)

project(lec43_livelock LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lec43_livelock main.cpp)

include(GNUInstallDirs)
install(TARGETS lec43_livelock
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
