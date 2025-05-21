cmake_minimum_required(VERSION 3.16)

project(lec35_shared_data_init LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lec35_shared_data_init main.cpp)

include(GNUInstallDirs)
install(TARGETS lec35_shared_data_init
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
