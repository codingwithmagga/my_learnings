#include <iostream>
#include <thread>

using namespace std;

void hello(int n)
{
    std::this_thread::sleep_for(chrono::seconds(n));
    cout << "hello from thr " << n << endl;
}

int main()
{
    std::thread thr1(hello, 1);
    std::thread thr2(hello, 2);
    std::thread thr3(hello, 3);

    thr1.join();
    thr2.join();
    thr3.join();

    cout << "hello main" << endl;

    return 0;
}
