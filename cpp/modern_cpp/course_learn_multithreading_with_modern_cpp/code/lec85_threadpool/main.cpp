#include <functional>
#include <iostream>
#include <mutex>
#include <queue>

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

void test() { }

using Func = std::function<void()>;
class Threadpool {

public:
    Threadpool()
    {
        const auto numCores = thread::hardware_concurrency();
        for (int i = 0; i < numCores; ++i) {
            threads.push_back(thread(&Threadpool::worker, this));
        }

        cout << "Pool created with " << numCores << " cores" << endl;
    }

    ~Threadpool()
    {
        for (auto& thread : threads) {
            thread.join();
        }
    }

    void submit(Func func)
    {
        cq.push(func);
    }

private:
    void worker()
    {
        while (true) {
            auto task = cq.front();
            task();
        }
    }

    vector<thread> threads;
    ConcurrentQueue<Func> cq;
};

void task()
{
    lock_guard lck(coutMut);
    cout << "id: " << this_thread::get_id() << " starts" << endl;
    this_thread::sleep_for(100ms);
    cout << "id: " << this_thread::get_id() << " ends" << endl;
}

int main()
{
    Threadpool pool;

    for (int i = 0; i < 20; ++i) {
        pool.submit(task);
    }

    this_thread::sleep_for(5s);

    return 0;
}
