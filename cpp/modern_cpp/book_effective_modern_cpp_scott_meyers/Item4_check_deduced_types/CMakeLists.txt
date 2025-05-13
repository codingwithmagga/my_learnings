cmake_minimum_required(VERSION 3.16)

project(check_deduced_types LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(check_deduced_types main.cpp)

include(GNUInstallDirs)
install(TARGETS check_deduced_types
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
