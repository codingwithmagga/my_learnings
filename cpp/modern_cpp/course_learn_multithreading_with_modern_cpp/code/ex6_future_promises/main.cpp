#include <future>
#include <iostream>

using namespace std;

void add(promise<int>& pr, int a, int b)
{
    this_thread::sleep_for(2s);
    pr.set_value(a + b);
}

void read(future<int>& fut)
{
    cout << "Waiting for the result." << endl;
    cout << "Result is " << fut.get() << endl;
}

void test(int a)
{
    cout << "hello " << a << endl;
}

int main()
{
    std::promise<int> promise;
    auto fut = promise.get_future();

    thread writeThr(add, std::ref(promise), 3, 5);
    thread readThr(read, std::ref(fut));

    writeThr.join();
    readThr.join();

    int a = 2;
    test(std::move(a));

    return 0;
}
