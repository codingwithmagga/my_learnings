#include "max_utils.hpp"

#include <string>
#include <iostream>

int main()
{
    mymax(3, 5);
    mymax(2.5, 7.1);
    mymax(std::string("aa"), std::string("zz"));

    if (mymax("aa", "zz") != "zz")
    {
        std::cout << "error " << std::endl;
    }
    if (mymax("43", "zz") != "zz")
    {
        std::cout << "error " << std::endl;
    }
    if (mymax("aa", "56") != "aa")
    {
        std::cout << "error " << std::endl;
    }
}

/*
    Questions:

    1. Why is a special handling for `const char*` necessary?
        If not the pointer would be compared not the containing characters. T is deduced to char* in the general case.

    2. Which version is selected for `mymax("abc", "xyz")`?
        The special version for const char* is selected.

    3. What happens for `mymax(4, 4.2)` with the generic version?
        T could be deduced to int or double, but T has to be equal.

    4. How could you support mixed types without forcing explicit casts?
        Add a second template parameter. For non-pointer built in types the compiler can cast the values and deduce the return type.
*/