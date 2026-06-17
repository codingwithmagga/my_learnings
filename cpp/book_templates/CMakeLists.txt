cmake_minimum_required(VERSION 3.25)

project(templates_book LANGUAGES CXX)

set(BOOST_INCLUDE_LIBRARIES type_index)
set(BOOST_ENABLE_CMAKE ON)

include(FetchContent)
FetchContent_Declare(
    Boost
    URL https://github.com/boostorg/boost/releases/download/boost-1.88.0/boost-1.88.0-cmake.7z
    USES_TERMINAL_DOWNLOAD TRUE
    DOWNLOAD_NO_EXTRACT FALSE
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(Boost)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(chapter_1)
add_subdirectory(chapter_2)