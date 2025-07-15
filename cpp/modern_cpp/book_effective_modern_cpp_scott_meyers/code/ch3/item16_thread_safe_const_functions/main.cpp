#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

using namespace std::chrono_literals;

class Point {
public:
    Point(const double x, const double y) noexcept
        : x(x)
        , y(y)
    {
    }

    double distanceFromOrigin() const noexcept
    {
        ++callCount;
        return std::sqrt((x * x) + (y * y));
    }

    auto getCallCount() const noexcept
    {
        return callCount.load();
    }

private:
    mutable std::atomic<unsigned> callCount { 0 };
    double x, y;
};

class Widget {
public:
    int expensiveComputation1() const
    {
        std::this_thread::sleep_for(500ms);
        return 2;
    }
    int expensiveComputation2() const
    {
        std::this_thread::sleep_for(400ms);
        return 1;
    }

    int magicValue() const
    {
        std::lock_guard<std::mutex> guard(m);
        if (cacheValid)
            return cachedValue;
        else {
            std::cout << "Calculate magic value.\n";

            auto val1 = expensiveComputation1();
            auto val2 = expensiveComputation2();

            cachedValue = val1 + val2;
            cacheValid = true;

            std::cout << "Finish calculation of magic value.\n";

            return cachedValue;
        }
    }

private:
    mutable std::mutex m;
    mutable int cachedValue;
    mutable bool cacheValid { false };
};

int main()
{
    {
        const Point p { 1.0, 4.0 };
        const int numThreads = 10;
        std::vector<std::thread> threads(numThreads);

        for (int i = 0; i < numThreads; ++i) {
            threads[i] = std::thread([&p]() { p.distanceFromOrigin(); });
        }

        for (auto& thread : threads) {
            thread.join();
        }

        std::cout << "Call count: " << p.getCallCount() << "\n\n";
    }
    {
        const Widget w {};
        const int numThreads = 10;
        std::vector<std::thread> threads(numThreads);
        std::mutex m;

        for (int i = 0; i < numThreads; ++i) {
            threads[i] = std::thread([&w, &m]() {
                std::lock_guard<std::mutex> guard(m);
                std::cout << w.magicValue() << " "; });
        }

        for (auto& thread : threads) {
            thread.join();
        }

        std::cout << "\n";
    }
}
