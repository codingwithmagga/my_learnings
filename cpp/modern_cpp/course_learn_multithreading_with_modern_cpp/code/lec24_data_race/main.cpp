#include <iostream>
#include <thread>

using namespace std;

void print(string str)
{
    for (int i = 0; i < 10; ++i) {
        cout << str[0] << str[1] << str[2] << endl;
    }
}

int main()
{
    std::jthread thr1(print, "abc");
    std::jthread thr2(print, "def");
    std::jthread thr3(print, "xyz");

    return 0;
}
