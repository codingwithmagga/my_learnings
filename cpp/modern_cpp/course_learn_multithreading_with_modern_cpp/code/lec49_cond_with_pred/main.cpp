// Condition variable with predicate
// Example with multiple waiting threads
#include <condition_variable>
#include <iostream>
#include <string>
#include <thread>

using namespace std;
using namespace std::chrono;

// The shared data
std::string sdata;

// Mutex to protect critical sections
std::mutex mut;

// The condition variable
std::condition_variable cond_var;

// bool flag for predicate
bool condition = false;

// Waiting thread
void reader()
{
    // Lock the mutex
    std::cout << "Reader thread locking mutex" << endl;
    std::unique_lock<std::mutex> uniq_lck(mut);
    std::cout << "Reader thread has locked the mutex" << endl;

    // Call wait()
    // This will unlock the mutex and make this thread
    // sleep until the condition variable wakes us up
    std::cout << "Reader thread sleeping..." << endl;

    // Lambda predicate that checks the flag
    cond_var.wait(uniq_lck, [] { return condition; });

    // The condition variable has woken this thread up
    // and locked the mutex
    std::cout << "Reader thread " << std::this_thread::get_id() << " wakes up" << endl;

    // Display the new value of the string
    std::cout << "Data is \"" << sdata << "\"" << endl;
    std::this_thread::sleep_for(2s);
    std::cout << "Reader thread unlocks the mutex" << endl;
}

// Notifying thread
void writer()
{
    {
        // Lock the mutex
        std::cout << "Writer thread locking mutex" << endl;

        // Lock the mutex
        // This will not be explicitly unlocked
        // std::lock_guard is sufficient
        std::lock_guard<std::mutex> lck_guard(mut);
        std::cout << "Writer thread has locked the mutex" << endl;

        // Pretend to be busy...
        std::this_thread::sleep_for(2s);

        // Modify the string
        std::cout << "Writer thread modifying data..." << endl;
        sdata = "Populated";

        // Set the flag
        condition = true;

        std::cout << "Writer thread unlocks the mutex" << endl;
    }

    // Notify the condition variable
    std::cout << "Writer thread sends notification" << endl;

    // cond_var.notify_all();

    // for (int i = 0; i < 3; ++i)
    cond_var.notify_one();
}

int main()
{
    // Initialize the shared string
    sdata = "Empty";

    // Display its initial value
    std::cout << "Data is \"" << sdata << "\"" << endl;

    // The notification is not lost,
    // even if the writer thread finishes before the reader thread starts
    // or there is a "spurious wakeup" (wait returns without a notification)
    std::thread write(writer);
    std::thread read1(reader);
    std::this_thread::sleep_for(10ms);
    std::thread read2(reader);
    std::this_thread::sleep_for(10ms);
    std::thread read3(reader);
    std::this_thread::sleep_for(10ms);

    write.join();
    read1.join();
    read2.join();
    read3.join();
}
