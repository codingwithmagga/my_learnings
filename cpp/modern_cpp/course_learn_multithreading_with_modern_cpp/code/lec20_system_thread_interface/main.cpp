#include <iostream>
#include <thread>

using namespace std;

void hello_world()
{
    std::this_thread::sleep_for(2s);
    cout << "hello thread: " << std::this_thread::get_id() << '\n';
}

int main()
{
    std::thread thread(hello_world);

    cout << "hello thread bf join: " << thread.get_id() << endl;

    thread.join();

    cout << "hello thread af join: " << thread.get_id() << '\n';
    cout << "main thread: " << std::this_thread::get_id() << '\n';

    return 0;
}
