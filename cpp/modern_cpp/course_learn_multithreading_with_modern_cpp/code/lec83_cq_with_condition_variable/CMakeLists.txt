cmake_minimum_required(VERSION 3.16)

project(lec83_cq_with_condition_variable LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lec83_cq_with_condition_variable main.cpp)

include(GNUInstallDirs)
install(TARGETS lec83_cq_with_condition_variable
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
