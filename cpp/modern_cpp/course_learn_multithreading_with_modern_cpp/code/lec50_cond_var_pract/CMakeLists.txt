cmake_minimum_required(VERSION 3.16)

project(lec50_cond_var_pract LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lec50_cond_var_pract main.cpp)

include(GNUInstallDirs)
install(TARGETS lec50_cond_var_pract
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
