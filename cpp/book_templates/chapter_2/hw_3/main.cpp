#include <iostream>

template<typename T1, typename T2>
struct Pair
{
    using first_type = T1;
    using second_type = T2;

    T1 first;
    T2 second;
};


// Tested with compiler X in C++17 and C++20 mode.
// CTAD for the aggregate worked only for C++20.
// I added a manual deduction guide.
template<typename T1, typename T2>
Pair(T1, T2) -> Pair<T1, T2>;

int main()
{
    Pair<int, double> p1{1, 2.5};

    Pair p2{1, 2.5};
    Pair p3{std::string("id"), 42};
}

/*
    Questions:

    1. What is a “templatized aggregate”?
        A templatized aggregate is an aggregate type (typically a struct with public data members and no user-provided constructors) 
        that is parameterized by template arguments.

    2. Why can CTAD for aggregates be interestingly different depending on the standard/compiler?
        CTAD was introduced in C++17, but support for aggregates was extended and refined in later standards. 
        Therefore aggregate deduction may behave differently depending on the compiler and language standard.

    3. What is the difference between:
    ```cpp
    Pair<int, double> p{1, 2.5};
    ```
    and
    ```cpp
    Pair p{1, 2.5};
    ```
    In first case the type of the parameters are given by the user. In the second case they are automatically deduced
    by the compiler.

    4. When can type aliases be helpful in such a structure?
        Type aliases improve readability and allow users of the type to refer to the contained types without knowing the template arguments.

*/