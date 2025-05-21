#include <iostream>
#include <thread>

using namespace std;

void hello_world()
{
    cout << "Hello World!\n";
}

int main()
{
    std::thread thread(hello_world);

    thread.join();

    return 0;
}
