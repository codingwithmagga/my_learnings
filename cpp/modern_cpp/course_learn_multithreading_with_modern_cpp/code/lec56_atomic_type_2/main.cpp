#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

using namespace std;

volatile int counter { 0 };
// atomic<int> counter { 0 };

mutex cntMut;

void task()
{
    for (int i = 0; i < 1'000'000; ++i) {
        ++counter;
    }
}

int main()
{
    auto start = std::chrono::high_resolution_clock::now();

    vector<thread> threads;
    for (int i = 0; i < 10; ++i) {
        threads.push_back(thread(task));
    }

    for (auto& thread : threads) {
        thread.join();
    }

    cout << "count: " << counter << endl;

    auto end = std::chrono::high_resolution_clock::now();

    // Calculate duration
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    std::cout << "Operation took " << duration << " milliseconds." << std::endl;

    return 0;
}
