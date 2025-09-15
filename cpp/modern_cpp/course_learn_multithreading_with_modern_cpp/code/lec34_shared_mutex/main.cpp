#include <chrono>
#include <iostream>
#include <shared_mutex>
#include <thread>
#include <vector>

using namespace std;
using namespace std::chrono_literals;

int x = 0;
std::shared_mutex mut;
std::mutex cout_mut;

void write()
{
    lock_guard lock(mut);
    ++x;
    cout << "write task: " << x << endl;
}

void read()
{
    shared_lock lock(mut);

    this_thread::sleep_for(100ms);
    lock_guard shared(cout_mut);
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
