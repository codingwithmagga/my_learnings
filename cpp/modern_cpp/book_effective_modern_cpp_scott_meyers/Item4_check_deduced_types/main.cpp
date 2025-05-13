#include <iostream>

template <typename T>
class TD;

int main()
{
    const int theAnswer = 42;

    auto x = theAnswer;
    auto y = &theAnswer;

    // Print the type of x and y as a compiler error if commented out
    // TD<decltype(x)> xType;
    // TD<decltype(y)> yType;

    std::cout << typeid(x).name() << '\n';
    std::cout << typeid(y).name() << '\n';

    return 0;
}
