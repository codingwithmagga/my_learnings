#include <condition_variable>
#include <iostream>
#include <string>
#include <thread>

using namespace std;

string dataString;

mutex dataMut;
mutex completedMut;

condition_variable dataCV;
condition_variable completedCV;

bool dataReady = false;
bool completed = false;

void download()
{
    cout << "Start download." << endl;

    for (int i = 0; i < 5; ++i) {

        cout << "Download package " << i << endl;
        this_thread::sleep_for(1s);

        lock_guard lck(dataMut);
        dataString += "Pck " + to_string(i) + " ";
        dataReady = true;

        dataCV.notify_all();
    }

    cout << "Finished download" << endl;
    std::lock_guard<std::mutex> lg(completedMut);
    completed = true;
    completedCV.notify_all();
}

void progressBar()
{

    this_thread::sleep_for(100ms);

    while (true) {
        unique_lock lck(dataMut);
        dataCV.wait(lck, []() { return dataReady; });

        dataReady = false;

        cout << "Received data " << dataString << endl;

        lck.unlock();

        unique_lock lckComplete(completedMut);
        if (completedCV.wait_for(lckComplete, 10ms, []() { return completed; })) {
            cout << "Progress bar finished" << endl;
            break;
        }
    }
}

void processData()
{
    unique_lock lck(completedMut);
    completedCV.wait(lck, []() { return completed; });

    cout << "Processing the data " << dataString << endl;
}

int main()
{
    jthread downloadThread(download);
    jthread progressBarThread(progressBar);
    jthread processDataThread(processData);

    return 0;
}
