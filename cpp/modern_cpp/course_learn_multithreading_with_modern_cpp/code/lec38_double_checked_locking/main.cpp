#include <iostream>
#include <thread>

using namespace std;

class Test {
public:
    Test()
    {
        cout << "Test constructed. " << endl;
    }

    void run()
    {
        cout << "run test" << endl;
    }
};

void process()
{
    static Test test;
    test.run();
}

int main()
{
    jthread thr1(process);
    jthread thr2(process);
    jthread thr3(process);
    jthread thr4(process);
    jthread thr5(process);

    return 0;
}
