cmake_minimum_required(VERSION 3.16)

project(lec78_shared_pointer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lec78_shared_pointer main.cpp)

include(GNUInstallDirs)
install(TARGETS lec78_shared_pointer
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
