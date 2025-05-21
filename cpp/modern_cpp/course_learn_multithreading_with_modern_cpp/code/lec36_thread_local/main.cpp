#include <iostream>
#include <random>
#include <thread>

using namespace std;

thread_local std::mt19937 mt;

void printRandom()
{
    std::uniform_int_distribution<int> uid(0, 100);
    for (int i = 0; i < 50; ++i)
        cout << uid(mt) << " ";
    cout << endl;
}

int main()
{
    jthread thr1(printRandom);
    thr1.join();
    jthread thr2(printRandom);
    thr2.join();

    return 0;
}
