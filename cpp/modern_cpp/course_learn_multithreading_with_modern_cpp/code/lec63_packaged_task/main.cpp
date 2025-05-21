#include <future>
#include <iostream>

using namespace std;

int add(int a, int b)
{
    this_thread::sleep_for(2s);
    return a + b;
}

int main()
{
    std::packaged_task<int(int, int)> task(add);
    auto fut = task.get_future();

    // task(5, 7);
    thread thr(std::move(task), 5, 7);

    cout << "Waiting for the result" << endl;
    cout << "5+7 is " << fut.get() << endl;

    thr.join();

    return 0;
}
