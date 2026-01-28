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

# Helper lib
add_subdirectory(helper_lib)

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

# Chapter 4 - smart pointer
add_subdirectory(ch4/item18_unique_ptr)
add_subdirectory(ch4/item19_shared_ptr)
add_subdirectory(ch4/item20_weak_ptr)
add_subdirectory(ch4/item21_make_fcts)
add_subdirectory(ch4/item22_pimpl_idiom)

# Chapter 5 - Move and forward
add_subdirectory(ch5/item23_move_forward)
add_subdirectory(ch5/item24_universal_references)
add_subdirectory(ch5/item25_move_forward_usage)
add_subdirectory(ch5/item26_overloading_universal_references)
add_subdirectory(ch5/item27_alternatives_overloading_ur)
add_subdirectory(ch5/item28_reference_collapsing)
add_subdirectory(ch5/item29_move_operations)
add_subdirectory(ch5/item30_perfect_forwarding_pitfalls)
