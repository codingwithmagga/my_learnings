#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

mutex mut1;
mutex mut2;

void funcA()
{
    cout << "A try lock mutex 1 and 2 " << endl;
    scoped_lock lck1(mut1, mut2);
    cout << "A Locked mutex 1 & 2 " << endl;
    this_thread::sleep_for(500ms);

    cout << "A Release all mutex " << endl;
}

void funcB()
{
    this_thread::sleep_for(50ms);

    cout << "B try lock mutex 1 and 2 " << endl;
    while (try_lock(mut1, mut2) != -1) {
        cout << "B failed to lock mutex 1 and 2 " << endl;
        this_thread::sleep_for(100ms);
    }
    cout << "B Locked mutex 1 & 2 " << endl;
    this_thread::sleep_for(100ms);

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
