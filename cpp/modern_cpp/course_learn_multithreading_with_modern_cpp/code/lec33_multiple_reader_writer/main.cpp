#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

using namespace std;
using namespace std::chrono_literals;

int x = 0;
std::mutex mut;

void write()
{
    lock_guard lock(mut);
    ++x;
    cout << "write task: " << x << endl;
}

void read()
{
    lock_guard lock(mut);

    this_thread::sleep_for(100ms);
    cout << "read task: " << x << endl;
}

int main()
{
    vector<jthread> threads;
    for (int i = 0; i < 20; ++i) {
        threads.push_back(jthread(read));
    }

    threads.push_back(jthread(write));
    threads.push_back(jthread(write));

    for (int i = 0; i < 20; ++i) {
        threads.push_back(jthread(read));
    }

    return 0;
}
