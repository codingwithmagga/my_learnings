#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

int x { 0 };

mutex mut1;

void func()
{
    unique_lock lock1(mut1);
    cout << " x was " << x << endl;
    while (x == 0) {
        x = 1 - x;
    }
    cout << " x is now " << x << endl;
}

int main()
{
    std::thread thr1 { func };
    std::thread thr2 { func };

    thr1.join();
    thr2.join();

    return 0;
}
