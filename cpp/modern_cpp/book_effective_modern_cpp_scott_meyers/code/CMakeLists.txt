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

# Chapter 1 - Deducing types
add_subdirectory(ch1/item1_template_type_deduction)
add_subdirectory(ch1/item2_auto_type_deduction)
add_subdirectory(ch1/item3_understand_decltype)
add_subdirectory(ch1/item4_check_deduced_types)

# Chapter 2 - auto
add_subdirectory(ch2/item5_prefer_auto)
add_subdirectory(ch2/item6_auto_undesired_types)

# Chapter 3 - modern c++
add_subdirectory(ch3/item7_object_initialization)
add_subdirectory(ch3/item8_prefer_nullptr)
add_subdirectory(ch3/item9_prefer_alias_declaration)
add_subdirectory(ch3/item10_prefer_scoped_enums)
add_subdirectory(ch3/item11_deleted_functions)
add_subdirectory(ch3/item12_use_override)
add_subdirectory(ch3/item13_use_const_iterators)
add_subdirectory(ch3/item14_use_noexcept)
add_subdirectory(ch3/item15_use_constexpr)
add_subdirectory(ch3/item16_thread_safe_const_functions)
add_subdirectory(ch3/item17_special_member_function_generation)
