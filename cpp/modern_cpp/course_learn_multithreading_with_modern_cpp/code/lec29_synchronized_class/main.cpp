#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

using namespace std;

class Vector {
public:
    void push_back(int i)
    {
        m.lock();
        v.push_back(i);
        m.unlock();
    }

    void print()
    {
        m.lock();
        for (const auto& e : v) {
            cout << e << ", ";
        }
        cout << endl;
        m.unlock();
    }

private:
    mutex m;
    vector<int> v;
};

void addElements(Vector& v)
{
    for (int i = 0; i < 5; ++i) {
        v.push_back(i);
        std::this_thread::sleep_for(50ms);
        v.print();
    }
    v.print();
}

int main()
{
    Vector v;
    std::jthread thr1(addElements, std::ref(v));
    std::jthread thr2(addElements, std::ref(v));
    std::jthread thr3(addElements, std::ref(v));

    return 0;
}
