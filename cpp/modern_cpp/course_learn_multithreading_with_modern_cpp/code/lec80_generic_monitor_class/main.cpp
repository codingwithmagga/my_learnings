#include <future>
#include <iostream>
#include <mutex>
#include <string>

using namespace std;

class Bank {
public:
    void deposit(int val)
    {
        amount += val;
    }
    void take(int val)
    {
        amount -= val;
    }
    void print()
    {
        cout << amount << endl;
    }

private:
    int amount = 0;
};

template <class T>
class Monitor {

public:
    Monitor(T data = T {})
        : data(data) { };

    template <typename Func>
    void operator()(Func func)
    {
        lock_guard lck(mut);
        func(data);
    };

private:
    T data;
    mutex mut;
};

int main()
{
    Monitor<Bank> monitorBank;

    monitorBank([](Bank bank) {
        bank.deposit(1000);
        bank.take(100);
        bank.print();
    });

    Monitor<string> monitorString("Hello: ");
    vector<future<void>> retFut;

    for (int i = 0; i < 10; ++i) {
        retFut.push_back(async([&monitorString, i] {
            monitorString([i](string& str) {
                                                         std::this_thread::sleep_for(10ms);
                                                         str.append(to_string(i));
                                                     });
            std::this_thread::sleep_for(100ms);
            monitorString([i](string& str) {
                std::this_thread::sleep_for(10ms);
                cout << str << endl;
            }); }));
    }

    for (const auto& fut : retFut) {
        fut.wait();
    }

    return 0;
}
