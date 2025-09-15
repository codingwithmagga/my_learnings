#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;
using namespace std::chrono_literals;

std::mutex mut;

void print(string str)
{
    for (int i = 0; i < 10; ++i) {
        std::unique_lock lock(mut);
        cout << str[0] << str[1] << str[2] << endl;
        lock.unlock();
        std::this_thread::sleep_for(20ms);
    }
}

int main()
{

    std::jthread thr1(print, "abc");
    std::jthread thr2(print, "def");
    std::jthread thr3(print, "ghi");
    std::jthread thr4(print, "jkl");
    std::jthread thr5(print, "mno");
    std::jthread thr6(print, "pqr");
    std::jthread thr7(print, "stu");
    std::jthread thr8(print, "vww");
    std::jthread thr9(print, "xyz");

    return 0;
}
