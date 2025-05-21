#include <iostream>
#include <thread>
#include <vector>

using namespace std;

int global = 0;

void increase()
{
    for (int i = 0; i < 100'000; ++i) {
        ++global;
    }
}

void startThreads(int n)
{
    std::vector<std::thread> tasks;
    for (int i = 0; i < n; ++i) {
        tasks.push_back(std::thread(increase));
    }
    for (int i = 0; i < n; ++i) {
        tasks[i].join();
    }
}

int main()
{
    int n = 2;
    startThreads(n);

    cout << "result:   " << global << endl;
    cout << "expected: " << n * 100'000 << endl;
    return 0;
}
