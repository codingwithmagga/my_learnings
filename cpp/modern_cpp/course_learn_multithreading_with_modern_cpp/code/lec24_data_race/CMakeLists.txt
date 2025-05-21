cmake_minimum_required(VERSION 3.16)

project(lec24_data_race LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lec24_data_race main.cpp)

include(GNUInstallDirs)
install(TARGETS lec24_data_race
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
