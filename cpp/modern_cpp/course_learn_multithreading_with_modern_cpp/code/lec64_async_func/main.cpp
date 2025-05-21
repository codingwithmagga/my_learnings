#include <future>
#include <iostream>

using namespace std;

int hello()
{
    std::this_thread::sleep_for(std::chrono::seconds(2));
    cout << "Hello World!" << endl;
    return 1;
}

int main()
{

    auto fut = std::async(hello);
    cout << "test" << endl;
    cout << "return " << fut.get() << endl;

    return 0;
}
