#include <iostream>

template <typename T>
void f1(T a)
{
    std::cout << "Called f1\n";
}

template <typename T>
void f2(T &a)
{
    std::cout << "Called f2\n";
}

template <typename T>
void f3(const T &a)
{
    std::cout << "Called f3\n";
}

template <typename T>
void f4(T *a)
{
    std::cout << "Called f4\n";
}

int main()
{
    int x = 0;
    const int cx = 0;
    int *px = &x;
    const int *pcx = &cx;

    f1(x);  // Valid call, T=int, arg=int
    f1(cx); // Valid call, T=int, arg=int

    f2(x);  // Valid call, T=int, arg=int&
    f2(cx); // Valid call, T=const int, arg=const int&

    f3(x);  // Valid call, T=int, arg=const int&
    f3(cx); // Valid call, T=int, arg=const int&

    f4(px);  // Valid call, T=int, arg=int*
    f4(pcx); // Valid call, T=const int, arg=int*
}

/*
    Additional question:
    Explain the difference between T, T& and const T& with respect to deduction.

    T rips of all references, everyhting is passed by value
    T& Accepts only lvalues.
    const T& Accepts everything. Preserves value.
*/