cmake_minimum_required(VERSION 3.16)

project(lec33_multiple_reader_writer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lec33_multiple_reader_writer main.cpp)

include(GNUInstallDirs)
install(TARGETS lec33_multiple_reader_writer
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
