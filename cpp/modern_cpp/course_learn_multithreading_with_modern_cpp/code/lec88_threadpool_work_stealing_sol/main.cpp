#include <chrono>
#include <functional>
#include <iostream>
#include <mutex>
#include <queue>
#include <random>

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

        while (q.size() > max) {
            lck.unlock();
            std::this_thread::sleep_for(50ms);
            lck.lock();
        }

        q.push(val);
        cond_var.notify_one();
    }

    bool try_push(T& value)
    {
        std::unique_lock<std::timed_mutex> lck_guard(mut, std::defer_lock);

        if (!lck_guard.try_lock_for(1ms) || q.size() > max) {
            return false;
        }

        q.push(value);

        return true;
    }

    T front()
    {
        unique_lock lck(mut);

        cond_var.wait(lck, [this] { return !q.empty(); });

        T val = q.front();
        q.pop();

        return val;
    }

    bool try_front(T& value)
    {
        std::unique_lock<std::timed_mutex> lck_guard(mut, std::defer_lock);

        if (!lck_guard.try_lock_for(1ms) || q.empty()) {
            return false;
        }

        value = q.front();
        q.pop();

        return true;
    }

private:
    queue<T> q;
    timed_mutex mut;
    size_t max = 200;

    std::condition_variable cond_var;
};

void test() { }

using Func = std::function<void()>;
class Threadpool {

public:
    Threadpool()
    {
        thread_count = thread::hardware_concurrency();
        for (int i = 0; i < thread_count; ++i) {
            threads.push_back(thread(&Threadpool::worker, this, i));
        }

        cq = std::make_unique<ConcurrentQueue<Func>[]>(thread_count);

        cout << "Pool created with " << thread_count << " cores" << endl;
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

        int i;

        do {
            i = get_random();
        } while (!cq[i].try_push(func));
    }

private:
    void worker(int idx)
    {
        while (true) {
            // Number of queues we have checked so far
            int visited = 0;
            Func task;

            // Take a task function off our queue
            int i = idx;

            while (!cq[i].try_front(task)) {
                // Nothing on this queue
                // Pick another queue at random
                i = get_random();

                // Hot loop avoidance
                // If we have checked "enough" queues, pause for a while
                // then start again with our own queue
                if (++visited == thread_count) {
                    std::this_thread::sleep_for(10ms);
                    visited = 0;
                    i = idx;
                }
            }

            // Invoke the task function
            task();
        }
    }

    int get_random()
    {
        std::lock_guard<std::mutex> lck_guard(rand_mut);
        std::uniform_int_distribution<int> dist(0, thread_count - 1);
        return dist(mt);
    }

    vector<thread> threads;
    std::unique_ptr<ConcurrentQueue<Func>[]> cq;
    std::mutex pos_mut;
    std::mutex rand_mut;
    unsigned int thread_count;
    int pos { 0 };
    std::mt19937 mt;
};

void task()
{
    this_thread::sleep_for(100ms);
    lock_guard lck(coutMut);
    cout << "id: " << this_thread::get_id() << " ends" << endl;
}

void taskLong()
{
    this_thread::sleep_for(5s);
    lock_guard lck(coutMut);
    cout << "id: " << this_thread::get_id() << " ends" << endl;
}

int main()
{
    Threadpool pool;

    pool.submit(taskLong);
    for (int i = 0; i < 200; ++i) {
        pool.submit(task);
    }

    this_thread::sleep_for(5s);

    return 0;
}
