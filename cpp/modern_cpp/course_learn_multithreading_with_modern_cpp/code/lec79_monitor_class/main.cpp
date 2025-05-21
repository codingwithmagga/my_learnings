#include <iostream>
#include <mutex>

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

class BankMonitor {

public:
    void deposit(int val)
    {
        lock_guard lck(mut);
        bank.deposit(val);
    }
    void take(int val)
    {
        lock_guard lck(mut);
        bank.take(val);
    }
    void print()
    {
        lock_guard lck(mut);
        bank.print();
    }

private:
    Bank bank;
    mutex mut;
};

int main()
{
    BankMonitor bank;

    thread thr([&bank] {
        bank.deposit(1000);
        bank.take(100);
        bank.print();
    });
    thr.join();

    return 0;
}
