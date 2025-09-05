#include <chrono>
#include <iostream>
#include <source_location>
#include <thread>
#include <vector>

using namespace std::chrono_literals;

template <typename T>
void f(T&& param)
{
    std::cout << "Function f: " << std::source_location::current().function_name() << std::endl;
    std::this_thread::sleep_for(10ms);
}

template <typename T>
void fVec(std::vector<T>&& param)
{
    std::cout << "Function fVec: " << std::source_location::current().function_name() << std::endl;
}

class Widget { };

auto timeFuncInvocation = [](auto&& func, auto&&... params) {
    auto start = std::chrono::high_resolution_clock::now();

    std::forward<decltype(func)>(func)(std::forward<decltype(params)>(params)...);

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Time elapsed: " << duration.count() << " ms" << std::endl;
};

int main()
{
    Widget w;

    f(w);
    f(std::move(w));

    std::cout << std::endl;

    std::vector<int> v { 1, 2 };
    f(v); // According to the book this should be an error! But even using C++-14 this seems to be allowed.
    f(std::move(v));

    std::cout << std::endl;

    Widget w2;
    timeFuncInvocation(f<Widget&>, w2);
    timeFuncInvocation(f<Widget>, std::move(w2));
}
