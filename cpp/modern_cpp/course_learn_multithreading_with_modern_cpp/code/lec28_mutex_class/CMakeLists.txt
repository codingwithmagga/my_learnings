cmake_minimum_required(VERSION 3.16)

project(lec28_mutex_class LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lec28_mutex_class main.cpp)

include(GNUInstallDirs)
install(TARGETS lec28_mutex_class
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
