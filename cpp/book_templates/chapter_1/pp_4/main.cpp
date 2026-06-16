#include <iostream>

template <typename TargetType = int, typename T>
TargetType convert(T val)
{
    return static_cast<TargetType>(val);
}

int main()
{
    auto a = convert<int>(4.7);
    auto b = convert<double>(3);
    auto c = convert<>(5);
}

/*
    Additional Questions:

    1. Which template parameter should have a default?
        The target type (TargetType) should have a default, because it cannot be deduced from the function argument.
    2. Which types are deduced automatically and which are not?
        Only the input type T is deduced. The target type is not deducible.
    3. Why can `<>` sometimes be omitted and sometimes not?
        The <> can be omitted if all template parameters are either deduced or have default values.

*/