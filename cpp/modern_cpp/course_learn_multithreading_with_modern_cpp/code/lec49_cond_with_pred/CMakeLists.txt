cmake_minimum_required(VERSION 3.16)

project(lec49_cond_with_pred LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lec49_cond_with_pred main.cpp)

include(GNUInstallDirs)
install(TARGETS lec49_cond_with_pred
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
