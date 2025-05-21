#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

using namespace std;

class Test {
public:
    Test() { cout << "test constructed" << endl; }
    void increase() { ++x; }

    int getX() { return x; }

private:
    int x = 0;
};

atomic<Test*> testAt = new Test;
std::mutex process_mutex;

void process()
{
    for (int i = 0; i < 1e6; ++i) {
        Test* ptr = testAt;
        std::lock_guard<std::mutex> lk(process_mutex);
        ptr->increase();
    }
}

int main()
{

    vector<thread> threads;
    for (int i = 0; i < 5; ++i) {
        threads.push_back(thread(process));
    }

    for (auto& thread : threads) {
        thread.join();
    }

    Test* ptr = testAt;
    cout << "val: " << ptr->getX() << endl;
    return 0;
}
