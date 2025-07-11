#include <chrono>
#include <iostream>
#include <string>
#include <vector>

class ExpensiveWidget {
    std::vector<std::vector<std::string>> data;

public:
    ExpensiveWidget()
        : data(100, std::vector<std::string>(100, "test"))
    {
    }

    ExpensiveWidget(const ExpensiveWidget& wRhs)
        : data(wRhs.data)
    {
        // Need to add this, otherwise the compiler does to much optimization
        if (check()) {
            throw std::exception("test");
        }
    };

    ExpensiveWidget(ExpensiveWidget&& wRhs)
        : data(std::move(wRhs.data))
    {
        if (check()) {
            throw std::exception("test");
        }
    };

    bool check() { return false; }
};

class ExpensiveWidgetNoExcept {
    std::vector<std::vector<std::string>> data;

public:
    ExpensiveWidgetNoExcept()
        : data(100, std::vector<std::string>(100, "test"))
    {
    }

    ExpensiveWidgetNoExcept(const ExpensiveWidgetNoExcept& wRhs)
        : data(wRhs.data)
    {
        if (check()) {
            int i = 0;
        }
    };

    ExpensiveWidgetNoExcept(ExpensiveWidgetNoExcept&&) noexcept
    {
        if (check()) {
            int i = 0;
        }
    };

    bool check() { return false; }
};

template <class C>
void runTest(const std::string& testName)
{
    auto start = std::chrono::high_resolution_clock::now();

    std::vector<C> vw;

    for (int i = 0; i < 1'000; ++i) {
        C c;
        vw.push_back(std::move(c));
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << testName << " took: " << duration.count() << " ms\n";
}

int main()
{
    runTest<ExpensiveWidget>("Move (no noexcept)");
    runTest<ExpensiveWidgetNoExcept>("Move (noexcept)");

    return 0;
}
