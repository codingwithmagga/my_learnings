#include <iostream>
#include <mutex>
#include <vector>

using namespace std;

class Semaphore {
public:
    void acquire()
    {
        unique_lock lck(mut);
        cout << "get resource ";
        printCount();

        while (counter == 0) {
            cout << "waiting for resource" << endl;
            cv.wait(lck);
        }
        --counter;
    }
    void release()
    {
        lock_guard lck(mut);

        if (counter < maxCounter) {
            ++counter;
        }
        cout << "res added ";
        printCount();

        cv.notify_all();
    }

    void printCount() { cout << "count: " << counter << endl; }

private:
    mutex mut;
    condition_variable cv;
    int counter = 5;
    int maxCounter = 100;
};

int main()
{

    Semaphore sem;

    vector<jthread> threads;

    for (int i = 0; i < 10; ++i) {
        threads.push_back(jthread([&sem]() { sem.acquire(); }));
    }
    for (int i = 0; i < 10; ++i) {
        threads.push_back(jthread([&sem]() { sem.release(); }));
    }
    for (int i = 0; i < 5; ++i) {
        threads.push_back(jthread([&sem]() { sem.acquire(); }));
    }

    this_thread::sleep_for(2s);
    cout << "End count: ";
    sem.printCount();

    return 0;
}
