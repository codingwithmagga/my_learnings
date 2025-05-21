cmake_minimum_required(VERSION 3.16)

project(lec57_atomic_operations LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lec57_atomic_operations main.cpp)

include(GNUInstallDirs)
install(TARGETS lec57_atomic_operations
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
