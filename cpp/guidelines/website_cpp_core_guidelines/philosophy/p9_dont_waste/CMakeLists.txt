cmake_minimum_required(VERSION 3.16)

project(p9_dont_waste LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(p9_dont_waste main.cpp)

include(GNUInstallDirs)
install(TARGETS p9_dont_waste
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
