#include <iostream>
#include <string>
#include <thread>
#include <vector>

using namespace std;

void fizzbuzz()
{
    int n = 20;
    vector<string> children { "Abdul", "Bart", "Claudia", "Divya" };

    for (int i = 1; i <= n; ++i) {
        string num;

        if (i % 3 == 0) {
            num += "fizz";
        }
        if (i % 5 == 0) {
            num += "buzz";
        }
        if (num.empty()) {
            num = to_string(i);
        } else {
            num += "!";
        }

        cout << children[(i - 1) % children.size()] << " says " << num << "\n";
    }
}

int main()
{
    std::thread fizzbuzzThread(fizzbuzz);
    fizzbuzzThread.join();

    return 0;
}
