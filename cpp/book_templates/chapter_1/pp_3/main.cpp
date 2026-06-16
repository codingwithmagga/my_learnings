#include <iostream>

template <typename T, typename U>
bool is_same_value(T a, U b)
{
    return a == b;
}

int main()
{
    std::cout << "Is 42==42: " << std::boolalpha << is_same_value(42, 42) << "\n";
    std::cout << "Is 42==42.0: " << is_same_value(42, 42.0) << "\n";
    std::cout << "Is 'a'==97: " << is_same_value('a', 97) << "\n";
    std::cout << "Is \"hi\"==\"hi\": " << is_same_value("hi", "hi") << "\n";
}

/*
    Additional Questions:

    1. How many template parameters do you need?
        2 template parameters

    2. What return type would you choose?
        bool, because it is a comparision

    3. What might be problematic or surprising when comparing different types?
        Rounding could be potentially surprising, e.g. is 42 the same as 42.2?
        In my implementation I rely on automatic conversion.
        Theroretically one can use static_cast to cast T or U to the other type, but which one should I choose?

    4. Does is_same_value("hi", "hi") behave as expected?
        Not always since this will be a pointer comparision (T=const char*).

*/