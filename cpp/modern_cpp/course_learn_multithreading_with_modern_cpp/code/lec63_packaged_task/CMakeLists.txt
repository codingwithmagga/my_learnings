cmake_minimum_required(VERSION 3.16)

project(lec63_packaged_task LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lec63_packaged_task main.cpp)

include(GNUInstallDirs)
install(TARGETS lec63_packaged_task
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
