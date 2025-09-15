cmake_minimum_required(VERSION 3.16)

project(lec87_threadpool_work_stealing_issue LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lec87_threadpool_work_stealing_issue main.cpp)

include(GNUInstallDirs)
install(TARGETS lec87_threadpool_work_stealing_issue
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
