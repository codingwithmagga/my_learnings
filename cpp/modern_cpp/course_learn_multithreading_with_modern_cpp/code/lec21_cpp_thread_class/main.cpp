#include <iostream>
#include <thread>

using namespace std;

void hello()
{
    try {
        throw std::exception("exception from hello");
    } catch (std::exception& e) {
        cout << "Caught exception in hello " << e.what() << '\n';
    }

    cout << "hello from fct \n";
    cout << "in hello fct: " << std::this_thread::get_id() << '\n';
}

void hello_world(std::thread&& thr)
{
    cout << "hello thread: " << thr.get_id() << '\n';
    thr.join();
}

std::thread getThread()
{
    return std::thread(hello);
}

int main()
{
    auto thr = getThread();
    try {
        hello_world(std::move(thr));
    } catch (std::exception& e) {
        cout << "Caught exception in main " << e.what() << '\n';
    }

    cout << "main thread: " << std::this_thread::get_id() << '\n';

    return 0;
}
