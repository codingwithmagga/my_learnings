cmake_minimum_required(VERSION 3.16)

project(lec75_transform_reduce_practical LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lec75_transform_reduce_practical main.cpp)

include(GNUInstallDirs)
install(TARGETS lec75_transform_reduce_practical
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
