#include <iostream>

template <typename Ret = int, typename T, typename U>
Ret add(T a, U b)
{
    return static_cast<Ret>(a + b);
}

int main()
{
    auto val1 = add(3, 4);
    if (val1 != 7 || !std::is_same<decltype(val1), int>::value)
    {
        std::cout << "Error val1" << std::endl;
    }

    auto val2 = add(3, 4.5);
    if (val2 != 7 || !std::is_same<decltype(val2), int>::value)
    {
        std::cout << "Error val2" << std::endl;
    }

    auto val3 = add<double>(3, 4);
    if (abs(val3 - 7.0) > 1e-8 || !std::is_same<decltype(val3), double>::value)
    {
        std::cout << "Error val3" << std::endl;
    }

    auto val4 = add<float>(3.4f, 4);
    if (abs(val4 - 7.4) > 1e-5 || !std::is_same<decltype(val4), float>::value)
    {
        std::cout << "Error val4" << std::endl;
    }

    auto val5 = add<short>(3, 4);
    if (val5 != 7 || !std::is_same<decltype(val5), short>::value)
    {
        std::cout << "Error val5" << std::endl;
    }

    auto val6 = add('a', 'b');
    if (val6 == static_cast<char>(195) || !std::is_same<decltype(val6), int>::value)
    {
        std::cout << "Error val6" << std::endl;
    }
}

/*
    Questions:

    1. Why is `template<typename T>` not sufficient here?
        Because different types for a and b are necessary, e.g. here add(3, 4.5).
        Also the return type needs to be explicitly setable by the user.

    2. When are default template arguments useful?
        They are usefull when a specific type makes sense when the compiler can't deduce it automatically.


    3. What differences arise between:
    * automatic return type -> deduced by compiler
    * explicitly specified return type? -> specified by user
*/