#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

using namespace std;

vector<int> v;
mutex mut;

void write(int n)
{
    for (int i = 0; i <= 10'000; ++i) {
        lock_guard lck(mut);
        v.push_back(n * i);
    }
}

int main()
{
    jthread thr1(write, 1);
    jthread thr2(write, 2);

    thr1.join();
    thr2.join();

    cout << "last ele: " << v.back() << endl;
    return 0;
}
