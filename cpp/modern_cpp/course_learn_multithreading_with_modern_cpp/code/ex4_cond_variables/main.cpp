#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

mutex dataMutex;
string dataString = "Empty";

bool writeReady = false;

void write()
{
    cout << "Warumup Phase writing" << endl;
    this_thread::sleep_for(100ms);
    lock_guard lck(dataMutex);

    cout << "Locked mutex, Doing work with data" << endl;
    this_thread::sleep_for(1s);
    dataString = "New big chunk of data";
    cout << "Unlock mutex, write ready" << endl;
    writeReady = true;
}

void read()
{
    unique_lock lck(dataMutex);
    cout << "Locked mutex, Try to read" << endl;

    while (!writeReady) {
        lck.unlock();
        this_thread::sleep_for(20ms);
        lck.lock();
    }

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
