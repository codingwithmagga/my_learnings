#include <iostream>
#include <vector>

#include <boost/type_index.hpp>

using namespace boost::typeindex;

struct BigObject
{
    std::string name;
    std::vector<int> data;
};

template <typename T>
void debugPrint(T x)
{
    std::cout << std::source_location::current().function_name() << std::endl;
    std::cout << "Type of x: " << type_id_with_cvr<decltype(x)>().pretty_name() << std::endl;
}

template <typename T>
void debugPrintByRef(T &x)
{
    std::cout << std::source_location::current().function_name() << std::endl;
    std::cout << "Type of x: " << type_id_with_cvr<decltype(x)>().pretty_name() << std::endl;
}

template <typename T>
void debugPrintConstRef(const T &x)
{
    std::cout << std::source_location::current().function_name() << std::endl;
    std::cout << "Type of x: " << type_id_with_cvr<decltype(x)>().pretty_name() << std::endl;
}

int main()
{
    int i = 3;
    const int ci = 4;
    std::string str{"Hello"};
    BigObject bigObj;

    debugPrint(i);      // T is dedcued to int, creates a cheap copy
    debugPrint(ci);     // T is deduced to int, creates a cheap copy
    debugPrint(str);    // T is deduced to std::string, copy can be expensive depending on string size
    debugPrint(bigObj); // T is deduced to BigObject, expensive copy

    std::cout << "\n";

    debugPrintByRef(i);      // T is deduced to int, no copy
    debugPrintByRef(ci);     // T is deduced to const int, no copy
    debugPrintByRef(str);    // T is deduced to std::string, no copy
    debugPrintByRef(bigObj); // T is deduced to BigObject, no copy

    std::cout << "\n";

    debugPrintConstRef(i);      // T is deduced to int, no copy
    debugPrintConstRef(ci);     // T is deduced to int, no copy
    debugPrintConstRef(str);    // T is deduced to std::string, no copy
    debugPrintConstRef(bigObj); // T is deduced to BigObject, no copy

    std::cout << "\n";

    debugPrint(42);                         // T is deduced to int, creates a cheap copy, can be optimized away
    debugPrintConstRef(std::string("tmp")); // T is deduced to std::string, no copy
}
/*
3. Provide a short recommendation:
   * when to use `T` - for small objects with a size less than a pointer
   * when to use `T&` - for big lvalue objects which needs to be mutable
   * when to use `const T&` - for big lvalue and rvalue objects which can be const
*/

/*
    Questions:

    1. Why can `T&` not accept everything?
        T& only binds to lvalues. So rvalues can't be accepted.

    2. Why is `const T&` often the “safe default”?
        Because it doesn't copy large objects and can accept everthing (lvalues, rvalues).

    3. When is `pass by value` still the better choice?
        When the types are smaller than a pointer. Or the parameter needs to be mutable.
*/