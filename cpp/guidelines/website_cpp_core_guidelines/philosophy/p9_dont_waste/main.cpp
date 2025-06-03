#include <cctype>
#include <chrono>
#include <cstring>
#include <iostream>

using namespace std;
using zstring = char*;

void lower_bad(zstring s)
{
    for (int i = 0; i < strlen(s); ++i)
        s[i] = tolower(s[i]);
}

void lower_better(zstring s)
{
    auto len = strlen(s);
    for (int i = 0; i < len; ++i)
        s[i] = tolower(s[i]);
}

int main()
{
    const int iterations = 1'000'000;
    char str1[] = "HELLO";
    char str2[] = "HELLO";

    // Time lower_bad()
    auto start_bad = chrono::high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i) {
        lower_bad(str1);
    }
    auto end_bad = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed_bad = end_bad - start_bad;

    // Time lower_better()
    auto start_better = chrono::high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i) {
        lower_better(str2);
    }
    auto end_better = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed_better = end_better - start_better;

    cout << "lower_bad() time:    " << elapsed_bad.count() << " seconds\n";
    cout << "lower_better() time: " << elapsed_better.count() << " seconds\n";

    return 0;
}
