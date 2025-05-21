#include <iostream>
#include <mutex>
#include <thread>

using namespace std;
std::timed_mutex mut_task;

void task1()
{
    cout << "locking mutex task1" << endl;
    mut_task.lock();

    this_thread::sleep_for(500ms);

    cout << "unlocked mutex task1" << endl;
    mut_task.unlock();
}

void task2()
{
    unique_lock lock(mut_task, defer_lock);

    this_thread::sleep_for(100ms);
    cout << "try locking mutex task2" << endl;
    // auto timepoint = std::chrono::system_clock::now() + 100ms;
    while (!lock.try_lock_for(100ms)) {
        cout << "lock not succesfull." << endl;
        //  timepoint = std::chrono::system_clock::now() + 100ms;
    }

    cout << "unlocked mutex task2" << endl;
}

int main()
{

    std::thread thr1(task1);
    std::thread thr2(task2);

    thr1.join();
    thr2.join();

    return 0;
}
