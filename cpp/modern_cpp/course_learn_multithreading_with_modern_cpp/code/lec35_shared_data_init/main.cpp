#include <iostream>
#include <thread>
#include <vector>

using namespace std;

class Singleton {
public:
    Singleton(const Singleton& rhs) = delete;
    Singleton& operator=(const Singleton& rhs) = delete;
    Singleton(Singleton&& rhs) = delete;
    Singleton& operator=(Singleton&& rhs) = delete;

    static Singleton* getInstance()
    {
        if (!instance) {
            instance = new Singleton;
        }
        return instance;
    }

private:
    Singleton() { };

    static Singleton* instance;
};

Singleton* Singleton::instance = nullptr;

void getSingleton()
{
    auto single = Singleton::getInstance();
    cout << single << endl;
}

class SingletonTS {
public:
    SingletonTS(const SingletonTS& rhs) = delete;
    SingletonTS& operator=(const SingletonTS& rhs) = delete;
    SingletonTS(SingletonTS&& rhs) = delete;
    SingletonTS& operator=(SingletonTS&& rhs) = delete;

    static SingletonTS& getInstance()
    {
        static SingletonTS instance;
        return instance;
    }

private:
    SingletonTS() { };
};

void getSingletonTS()
{
    cout << &SingletonTS::getInstance() << endl;
}

int main()
{

    vector<thread> threads;
    for (int i = 0; i < 5; ++i) {
        threads.push_back(thread(getSingletonTS));
    }

    for (int i = 0; i < 5; ++i) {
        threads[i].join();
    }

    return 0;
}
