#include <string>
#include <iostream>

template <typename T>
T mymax(T a, T b)
{
    return b < a ? a : b;
}

int main()
{
    std::cout << "mymax(3, 7): " << mymax(3, 7) << "\n";
    std::cout << "mymax(4.5, 2.1): " << mymax(4.5, 2.1) << "\n";
    std::cout << "mymax(std::string(\"abc\"), std::string(\"xyz\")): " << mymax(std::string("abc"), std::string("xyz")) << "\n";
}

/*
    Questions:

    1. Do you need to explicitly specify the template parameter for these calls?
       No, this is not necessary.

    2. What happens with mymax(3, 4.5)?
       Template arugment deduction will fail.

    3. Why?
       There are conflicting types: int and double.
*/