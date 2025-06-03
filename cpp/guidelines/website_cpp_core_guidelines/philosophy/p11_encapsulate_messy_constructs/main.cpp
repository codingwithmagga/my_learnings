#include <iostream>
#include <vector>

using namespace std;

void bad()
{
    int sz = 100;
    int* p = (int*)malloc(sizeof(int) * sz);
    int count = 0;
    // ...
    for (;;) {
        // ... read an int into x, exit loop if end of file is reached ...
        // ... check that x is valid ...
        int x = 2;
        if (count == sz)
            p = (int*)realloc(p, sizeof(int) * sz * 2);

        // return of realloc is not checked
        // sz is not updated

        p[count++] = x;
        // ...
    }
}

void better()
{
    vector<int> v;
    v.reserve(100);
    // ...
    int x;

    while (true) {
        std::cout << "> ";
        if (std::cin >> x) {
            // Add your check for valid input here
            v.push_back(x);
        } else {
            // If input fails (non-integer), break from loop
            std::cout << "Exiting loop due to invalid input." << std::endl;
            break;
        }
    }
}

int main()
{
    cout << "Hello World!" << endl;
    better();
    return 0;
}
