cmake_minimum_required(VERSION 3.16)

project(lec88_threadpool_work_stealing_sol LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lec88_threadpool_work_stealing_sol main.cpp)

include(GNUInstallDirs)
install(TARGETS lec88_threadpool_work_stealing_sol
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
