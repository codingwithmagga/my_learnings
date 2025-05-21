cmake_minimum_required(VERSION 3.28)

project(lec41_deadlock_avoidance LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lec41_deadlock_avoidance main.cpp)

include(GNUInstallDirs)
install(TARGETS lec41_deadlock_avoidance
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
