#include <iostream>
#include <thread>

using namespace std;

void hello()
{
    cout << "Hello Thread" << endl;
}

class ThreadGuard {
public:
    ThreadGuard(std::thread&& thr)
        : m_thr(std::move(thr))
    {
    }

    ~ThreadGuard()
    {
        if (m_thr.joinable()) {
            m_thr.join();
        }
    }

private:
    std::thread m_thr;
};

int main()
{
    std::jthread thr(hello);
    // ThreadGuard guard(std::move(thr));

    try {
        throw std::exception();
    } catch (std::exception& e) {
        std::cout << "Exception caught\n";
    }
}
