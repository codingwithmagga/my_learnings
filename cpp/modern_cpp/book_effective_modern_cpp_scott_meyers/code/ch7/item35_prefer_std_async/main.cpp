#include <future>
#include <iostream>

int doAsyncWork()
{
    std::cout << "Doing async work...\n";
    return 42;
}

int main()
{
    auto fut = std::async(doAsyncWork);
    std::thread t(doAsyncWork);

    t.join();
    std::cout << "Async work result: " << fut.get() << "\n";

    return 0;
}