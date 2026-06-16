#include <iostream>

/*
template <typename T>
void logValue(T x)
{
    std::cout << x << "\n";
}

template <typename T>
void logValue(T &x)
{
    std::cout << x << "\n";
}*/

template <typename T>
void logValue(const T &x)
{
    std::cout << x << "\n";
}

int main()
{
    /*
    1. Evaluate whether this overload set is reasonable
        It is not reasonable since in many cases the calls were ambigious.

    2. Identify cases where calls are ambiguous or problematic
        All calls are ambigious though the reason differ.

    3. Analyze these calls:
        In the second logValue fct the const from b is propagated to the template parameter T.
        In the first and third one and in all cases of a the template parameter T is int.
        The '42' can't be deduced in the second logValue fct (no rvalue possible).

    */
    int a = 1;
    const int b = 2;

    logValue(a);
    logValue(b);
    logValue(42);
}

/*
    Additional Questions:

    * Which version would you typically prefer in practice?
        It depends on the size of the object which is generally passed to logValue. In general I prefer void logValue(const T &x)
        which does not copy large types.

    * For which types is `pass by value` acceptable?
        For small types.

    * When is `const T&` the better choice?
        For large types, bigger than a pointer.

*/