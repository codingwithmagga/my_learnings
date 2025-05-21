cmake_minimum_required(VERSION 3.16)

project(lec61_lockfree_practical LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lec61_lockfree_practical main.cpp)

include(GNUInstallDirs)
install(TARGETS lec61_lockfree_practical
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
