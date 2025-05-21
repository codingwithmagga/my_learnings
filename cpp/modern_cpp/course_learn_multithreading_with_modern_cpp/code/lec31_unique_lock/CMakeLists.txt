cmake_minimum_required(VERSION 3.16)

project(lec31_unique_lock LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lec31_unique_lock main.cpp)

include(GNUInstallDirs)
install(TARGETS lec31_unique_lock
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
