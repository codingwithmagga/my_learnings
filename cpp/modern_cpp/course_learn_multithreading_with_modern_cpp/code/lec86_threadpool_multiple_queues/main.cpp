#include <chrono>
#include <functional>
#include <iostream>
#include <mutex>
#include <queue>

using namespace std;
using namespace std::literals;
using namespace std::chrono_literals;

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
    size_t max = 20;

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
            threads.push_back(thread(&Threadpool::worker, this, i));
        }

        cq = std::make_unique<ConcurrentQueue<Func>[]>(numCores);

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
        std::lock_guard<std::mutex> guard(pos_mut);
        cq[pos].push(func);

        pos = (pos + 1) % threads.size();
    }

private:
    void worker(int idx)
    {
        while (true) {
            auto task = cq[idx].front();
            task();
        }
    }

    vector<thread> threads;
    std::unique_ptr<ConcurrentQueue<Func>[]> cq;
    std::mutex pos_mut;
    int pos { 0 };
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
