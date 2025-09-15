#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;
using namespace std::chrono_literals;

mutex mut1, mut2;

void funcA()
{

    scoped_lock ulck1(mut1, mut2);
    cout << "A is chilling." << endl;
    this_thread::sleep_for(500ms);
}

void funcB()
{
    bool locked = false;

    scoped_lock ulck1(mut1, mut2);
    cout << "B is chilling." << endl;
    this_thread::sleep_for(500ms);
}

int main()
{

    jthread thr(funcA);
    jthread thr2(funcB);

    return 0;
}
