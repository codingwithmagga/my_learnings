cmake_minimum_required(VERSION 3.16)

project(ex2_data_races LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ex2_data_races main.cpp)

include(GNUInstallDirs)
install(TARGETS ex2_data_races
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
