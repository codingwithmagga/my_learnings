cmake_minimum_required(VERSION 3.16)

project(p11_encapsulate_messy_constructs LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(p11_encapsulate_messy_constructs main.cpp)

include(GNUInstallDirs)
install(TARGETS p11_encapsulate_messy_constructs
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
