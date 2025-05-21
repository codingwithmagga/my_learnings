cmake_minimum_required(VERSION 3.16)

project(lec81_semaphore LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lec81_semaphore main.cpp)

include(GNUInstallDirs)
install(TARGETS lec81_semaphore
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
