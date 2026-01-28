#include <vector>
#include <iostream>
#include <cstdint>

void f(const std::vector<int> &v)
{
    for (const auto val : v)
    {
        std::cout << val << ", ";
    }
    std::cout << "\n";
}

template <typename... Ts>
void fwd(Ts &&...params)
{
    f(std::forward<Ts>(params)...);
}

void fPtr(const int *ptr)
{
    if (!ptr)
    {
        std::cout << "nullptr \n";
        return;
    }
    std::cout << *ptr << "\n";
}

template <typename... Ts>
void fwdPtr(Ts &&...params)
{
    fPtr(std::forward<Ts>(params)...);
}

void fFunc(int (*pf)(int))
{
    auto retVal = pf(42);
    std::cout << "Return val: " << retVal << "\n";
}

template <typename... Ts>
void fwdFunc(Ts &&...params)
{
    fFunc(std::forward<Ts>(params)...);
}

int processVal(int value)
{
    std::cout << "Call processVal " << value << "\n";
    return ++value;
}
int processVal(int value, int priority)
{
    std::cout << "Call processVal " << value << ", " << priority << "\n";
    return ++value;
}

template <typename T>
T workOnVal(T param)
{
    std::cout << "Call workOnVal " << param << "\n";

    param += 4;
    return param;
}

using ProcessFuncType = int (*)(int);
ProcessFuncType processValPtr = processVal;

struct IPv4Header
{
    std::uint32_t
        version : 4,
        IHL : 4,
        DSCP : 6,
        ECN : 2,
        totalLength : 16;
};

int main()
{
    // Braced intializer

    f({1, 2, 3});
    // fwd({1, 2, 3}); // don't compile
    auto it = {1, 2, 3};
    fwd(it); // workaround

    // ----------------------------------

    std::cout << "\n";
    fPtr(0);
    fPtr(NULL);
    // fwdPtr(NULL); // don't compile
    fwdPtr(nullptr);

    // ----------------------------------

    std::cout << "\n";
    fFunc(processVal);
    // fwd(processVal); // don't compile
    fwdFunc(processValPtr);                           // workaround
    fwdFunc(static_cast<ProcessFuncType>(workOnVal)); // workaround

    // ----------------------------------

    std::cout << "\n";
    IPv4Header h{1, 1, 0, 0, 512};
    f({static_cast<int>(h.totalLength)});
    // fwd({h.totalLength}); // don't compile

    auto length = static_cast<int>(h.totalLength);
    fwd(std::vector<int>{length}); // workaround

    return 0;
}
