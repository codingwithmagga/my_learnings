cmake_minimum_required(VERSION 3.16)

project(lec53_future_promises LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lec53_future_promises main.cpp)

include(GNUInstallDirs)
install(TARGETS lec53_future_promises
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
