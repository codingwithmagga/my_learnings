#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

mutex dataMutex;
string dataString = "Empty";

condition_variable cond;

void write()
{
    cout << "Warumup Phase writing" << endl;
    this_thread::sleep_for(1s);
    lock_guard lck(dataMutex);

    cout << "Locked mutex, Doing work with data" << endl;
    this_thread::sleep_for(3s);
    dataString = "New big chunk of data";
    cout << "Unlock mutex, notify" << endl;

    cond.notify_all();
}

void read()
{
    unique_lock lck(dataMutex);
    cout << "Locked mutex, Try to read" << endl;

    cond.wait(lck);

    cout << "data at end: " << dataString << endl;
    cout << "Unlock mutex" << endl;
}

int main()
{
    cout << "data at start: " << dataString << endl;

    thread thrWrite(write);
    thread thrRead(read);

    thrWrite.join();
    thrRead.join();

    return 0;
}
