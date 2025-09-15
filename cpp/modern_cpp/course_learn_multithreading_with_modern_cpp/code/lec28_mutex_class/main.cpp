#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;
using namespace std::chrono_literals;

std::mutex mut;
std::mutex mut_task;

void print(string str)
{
    for (int i = 0; i < 5; ++i) {
        mut.lock();
        cout << str[0] << str[1] << str[2] << endl;
        mut.unlock();
    }
}

void task1()
{
    cout << "locking mutex task1" << endl;
    mut_task.lock();

    this_thread::sleep_for(500ms);

    mut_task.unlock();
    cout << "unlocked mutex task1" << endl;
}

void task2()
{

    this_thread::sleep_for(100ms);
    cout << "try locking mutex task2" << endl;
    while (!mut_task.try_lock()) {
        cout << "lock not succesfull." << endl;
        this_thread::sleep_for(100ms);
    }

    mut_task.unlock();
    cout << "unlocked mutex task2" << endl;
}

int main()
{
    /*
     std::jthread thr1(print, "abc");
     std::jthread thr2(print, "def");
     std::jthread thr3(print, "ghi");
     std::jthread thr4(print, "jkl");
     std::jthread thr5(print, "mno");
     std::jthread thr6(print, "pqr");
     std::jthread thr7(print, "stu");
     std::jthread thr8(print, "vww");
     std::jthread thr9(print, "xyz");
     */
    std::jthread thr1(task1);
    std::jthread thr2(task2);

    return 0;
}
