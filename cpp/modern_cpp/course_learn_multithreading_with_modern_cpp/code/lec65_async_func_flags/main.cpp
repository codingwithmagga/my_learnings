#include <chrono>
#include <future>
#include <iostream>
#include <thread>

using namespace std::chrono_literals;
using namespace std;

int func()
{
    cout << "Func thread " << this_thread::get_id() << endl;
    return 42;
}

void func2(string flag)
{
    cout << "Running on thread " << this_thread::get_id() << " with flag " << flag << endl;
}

int main()
{
    cout << "Main thread " << this_thread::get_id() << endl;

    auto result = std::async(launch::deferred, func);
    std::this_thread::sleep_for(1s);
    cout << "Waiting for result" << endl;
    std::cout << result.get() << '\n';

    return 0;
}
