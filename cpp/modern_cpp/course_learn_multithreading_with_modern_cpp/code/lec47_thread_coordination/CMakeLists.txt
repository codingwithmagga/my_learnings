cmake_minimum_required(VERSION 3.16)

project(lec47_thread_coordination LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lec47_thread_coordination main.cpp)

include(GNUInstallDirs)
install(TARGETS lec47_thread_coordination
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
