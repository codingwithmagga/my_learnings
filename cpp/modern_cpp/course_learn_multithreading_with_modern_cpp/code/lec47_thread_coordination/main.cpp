#include <iostream>
#include <mutex>
#include <string>
#include <thread>

using namespace std;

bool isUpdated = false;
bool isFinished = false;

string dataPackage;

mutex dataMutex;
mutex finishedMutex;

void download()
{

    cout << "start download..." << endl;

    for (int i = 0; i < 5; ++i) {
        std::this_thread::sleep_for(3s);

        cout << "receive package " << i << endl;

        lock_guard lck(dataMutex);
        dataPackage += "Block" + to_string(i) + " ";

        isUpdated = true;
    }

    cout << "finish download..." << endl;
    lock_guard lck(finishedMutex);

    isFinished = true;
}

void progressBar()
{
    while (true) {
        unique_lock lckData(dataMutex);

        while (!isUpdated) {
            lckData.unlock();
            std::this_thread::sleep_for(20ms);
            lckData.lock();
        }

        cout << "update data: " << dataPackage << endl;
        isUpdated = false;
        lckData.unlock();

        lock_guard lckFinish(finishedMutex);
        if (isFinished) {
            cout << "got all data, progress bar ends" << endl;
            break;
        }
    }
}

void processData()
{
    unique_lock lckFinish(finishedMutex);

    while (!isFinished) {
        lckFinish.unlock();
        std::this_thread::sleep_for(20ms);
        lckFinish.lock();
    }

    cout << "Processing data: " << dataPackage << endl;
}

int main()
{

    jthread downloadThread(download);
    jthread progressThread(progressBar);
    jthread processThread(processData);

    return 0;
}
