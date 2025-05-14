#include <iostream>
#include <source_location>

#include <boost/type_index.hpp>

using namespace boost::typeindex;

void someFunc(int, double) { }

template <typename T>
void f(T param)
{
    std::cout << std::source_location::current().function_name() << std::endl;
}

template <typename T>
void fIT(std::initializer_list<T> initList)
{
    std::cout << std::source_location::current().function_name() << std::endl;
}

int main()
{
    auto x = 27;
    const auto cx = x;
    const auto& rx = x;

    std::cout << "Type of x: " << type_id_with_cvr<decltype(x)>().pretty_name() << std::endl;
    std::cout << "Type of cx: " << type_id_with_cvr<decltype(cx)>().pretty_name() << std::endl;
    std::cout << "Type of rx: " << type_id_with_cvr<decltype(rx)>().pretty_name() << std::endl
              << std::endl;

    auto&& uref1 = x;
    auto&& uref2 = cx;
    auto&& uref3 = 27;

    std::cout << "Type of uref1: " << type_id_with_cvr<decltype(uref1)>().pretty_name() << std::endl;
    std::cout << "Type of uref2: " << type_id_with_cvr<decltype(uref2)>().pretty_name() << std::endl;
    std::cout << "Type of uref3: " << type_id_with_cvr<decltype(uref3)>().pretty_name() << std::endl
              << std::endl;

    const char name[] = "R. N. Briggs";
    auto arr1 = name;
    auto& arr2 = name;

    std::cout << "Type of name: " << type_id_with_cvr<decltype(name)>().pretty_name() << std::endl;
    std::cout << "Type of arr1: " << type_id_with_cvr<decltype(arr1)>().pretty_name() << std::endl;
    std::cout << "Type of arr2: " << type_id_with_cvr<decltype(arr2)>().pretty_name() << std::endl
              << std::endl;

    auto func1 = someFunc;
    auto& func2 = someFunc;

    std::cout << "Type of func1: " << type_id_with_cvr<decltype(func1)>().pretty_name() << std::endl;
    std::cout << "Type of func2: " << type_id_with_cvr<decltype(func2)>().pretty_name() << std::endl
              << std::endl;

    auto x1 = 27;
    auto x2(27);
    auto x3 = { 27 };
    auto x4 { 27 };
    // auto x5 = {12, 24, 42.0};  // error! can't deduce T for std::initializer_list<T>

    std::cout << "Type of x1: " << type_id_with_cvr<decltype(x1)>().pretty_name() << std::endl;
    std::cout << "Type of x2: " << type_id_with_cvr<decltype(x2)>().pretty_name() << std::endl;
    std::cout << "Type of x3: " << type_id_with_cvr<decltype(x3)>().pretty_name() << std::endl;
    // x4 is int, but should be std::initializer_list<int>?
    // Error in book, mentioned here: https://www.aristeia.com/BookErrata/emc++-errata.html at 11/22/14
    // type int is correct!
    std::cout << "Type of x4: " << type_id_with_cvr<decltype(x4)>().pretty_name() << std::endl
              << std::endl;

    auto xIT = { 11, 23, 9 };
    f(xIT);
    // f({ 11, 23, 9 }); // Can't be deduced, compiler error
    fIT({ 11, 23, 9 });

    return 0;
}
