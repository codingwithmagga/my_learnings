cmake_minimum_required(VERSION 3.16)

project(Item1_template_type_deduction LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Item1_template_type_deduction main.cpp)

include(GNUInstallDirs)
install(TARGETS Item1_template_type_deduction
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
