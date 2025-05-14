cmake_minimum_required(VERSION 3.16)

project(book_effective_modern_cpp_scott_meyers LANGUAGES CXX)

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

add_subdirectory(item1_template_type_deduction)
add_subdirectory(item2_auto_type_deduction)
add_subdirectory(item3_understand_decltype)
add_subdirectory(item4_check_deduced_types/)
