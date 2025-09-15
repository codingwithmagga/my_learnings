#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;
using namespace std::chrono_literals;

mutex mut1;
mutex mut2;

void funcA()
{
    cout << "A try lock mutex 1 " << endl;
    lock_guard lck1(mut1);
    cout << "A Locked mutex 1 " << endl;
    this_thread::sleep_for(100ms);
    cout << "A try lock mutex 2 " << endl;
    lock_guard lck2(mut2);
    cout << "A Locked mutex 2 " << endl;
    cout << "A Release all mutex " << endl;
}

void funcB()
{
    this_thread::sleep_for(50ms);
    cout << "B try lock mutex 1 " << endl;
    lock_guard lck1(mut1);
    cout << "B Locked mutex 1 " << endl;
    this_thread::sleep_for(50ms);
    cout << "B try lock mutex 2 " << endl;
    lock_guard lck2(mut2);
    cout << "B Locked mutex 2 " << endl;
    cout << "B Release all mutex " << endl;
}

int main()
{
    thread thrA(funcA);
    thread thrB(funcB);

    thrA.join();
    thrB.join();

    return 0;
}
