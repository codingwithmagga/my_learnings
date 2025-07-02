#include <iostream>

bool round_up = true;

int roundVal(double d)
{
    return (round_up) ? ceil(d) : d;
}

int main()
{
    double x = 7.3;
    std::cout << roundVal(x) << std::endl;

    round_up = !round_up;
    std::cout << roundVal(x) << std::endl;

    return 0;
}
