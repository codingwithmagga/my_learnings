#include <iostream>
#include <mutex>
#include <queue>
#include <string>

using namespace std;

mutex coutMut;

template <typename T>
class ConcurrentQueue {

public:
    void push(const T& val)
    {
        unique_lock lck(mut);

        if (q.size() >= max) {
            unique_lock lckCout(coutMut);
            cout << "Waiting cause q is full" << endl;
            lckCout.unlock();
            check_full.wait(lck, [this]() { return q.size() < max; });
        }

        q.push(val);
        check_empty.notify_all();
    }

    T front()
    {
        unique_lock lck(mut);

        if (q.empty()) {
            unique_lock lckCout(coutMut);
            cout << "Waiting cause q is empty" << endl;
            lckCout.unlock();
            check_empty.wait(lck, [this]() { return !q.empty(); });
        }

        T val = q.front();
        q.pop();
        check_full.notify_all();

        return val;
    }

private:
    queue<T> q;
    mutex mut;
    size_t max = 2;

    condition_variable check_empty;
    condition_variable check_full;
};

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
