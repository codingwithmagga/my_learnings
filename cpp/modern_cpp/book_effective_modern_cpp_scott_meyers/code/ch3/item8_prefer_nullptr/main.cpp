#include <iostream>
#include <mutex>

using MuxGuard = std::lock_guard<std::mutex>;

class Widget { };

void f(int)
{
    std::cout << "f(int) called\n";
}

void f(bool)
{
    std::cout << "f(bool) called\n";
}

void f(void*)
{
    std::cout << "f(void*) called\n";
}

int f1(std::shared_ptr<Widget>)
{
    std::cout << "f1(std::shared_ptr<Widget>) called\n";
    return 0;
}

double f2(std::unique_ptr<Widget>)
{
    std::cout << "f2(std::unique_ptr<Widget>) called\n";
    return 0.0;
}

bool f3(Widget*)
{
    std::cout << "f3(Widget*) called\n";
    return true;
}

template <typename FuncType, typename MuxType, typename PtrType>
decltype(auto) lockAndCall(FuncType func,
    MuxType& mutex, PtrType ptr)
{
    MuxGuard g(mutex);
    return func(ptr);
}

int main()
{

    std::cout << "Calling f(0):        ";
    f(0);

    std::cout << "Calling f(NULL):     ";
    f(NULL);

    std::cout << "Calling f(nullptr):  ";
    f(nullptr);
    std::cout << std::endl;

    // ---------------------------------------------------------------------

    std::mutex f1m, f2m, f3m;
    // auto result1 = lockAndCall(f1, f1m, 0);
    // auto result2 = lockAndCall(f2, f2m, NULL);
    auto result3 = lockAndCall(f3, f3m, nullptr);

    std::cout << "Result: " << result3 << std::endl;

    return 0;
}
