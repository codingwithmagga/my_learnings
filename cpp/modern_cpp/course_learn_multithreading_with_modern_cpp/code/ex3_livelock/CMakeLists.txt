cmake_minimum_required(VERSION 3.16)

project(ex3_livelock LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ex3_livelock main.cpp)

include(GNUInstallDirs)
install(TARGETS ex3_livelock
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
