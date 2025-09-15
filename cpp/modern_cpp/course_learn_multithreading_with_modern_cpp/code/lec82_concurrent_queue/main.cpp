#include <chrono>
#include <iostream>
#include <mutex>
#include <queue>
#include <string>

using namespace std;
using namespace std::chrono_literals;

template <typename T>
class ConcurrentQueue {

public:
    void push(const T& val)
    {
        lock_guard lck(mut);

        if (q.size() >= max) {
            throw std::exception("Full q");
        }

        q.push(val);
    }

    T front()
    {
        std::this_thread::sleep_for(200ms);
        lock_guard lck(mut);

        if (q.empty()) {
            throw std::exception("Empty q");
        }

        T val = q.front();
        q.pop();

        return val;
    }

private:
    queue<T> q;
    mutex mut;
    size_t max = 200;
};

mutex coutMut;

int main()
{
    ConcurrentQueue<string> cq;

    vector<thread> threads;

    try {
        for (int i = 0; i < 20; ++i) {

            threads.push_back(thread([&cq, i]() {
        string str("Hello ");
        str += to_string(i);
        cq.push(str); }));
        }

        for (int i = 0; i < 20; ++i) {

            threads.push_back(thread([&cq, i]() { auto val = cq.front(); lock_guard lck(coutMut); cout << val << endl; }));
        }
    } catch (std::exception& e) {
        cout << e.what() << endl;
    }

    for (auto& thread : threads) {
        thread.join();
    }

    return 0;
}
