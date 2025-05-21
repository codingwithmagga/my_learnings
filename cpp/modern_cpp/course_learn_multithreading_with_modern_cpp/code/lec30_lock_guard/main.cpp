#include <iostream>
#include <mutex>
#include <thread>

using namespace std;
std::mutex mut;
std::mutex mut_task;

void print(string str)
{
    for (int i = 0; i < 10; ++i) {
        try {
            std::lock_guard lock(mut);
            cout << str[0] << str[1] << str[2] << endl;
            throw exception("hello");
            std::this_thread::sleep_for(20ms);
        } catch (std::exception& e) {
            cout << "caught exc.: " << e.what() << endl;
        }
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
