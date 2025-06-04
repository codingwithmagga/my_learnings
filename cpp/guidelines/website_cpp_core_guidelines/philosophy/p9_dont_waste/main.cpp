#include <cctype>
#include <chrono>
#include <cstring>
#include <iomanip> // For std::fixed and std::setprecision
#include <iostream>

using namespace std;
using CString = char*;

// Lowercase a C-style string (unoptimized - calls strlen() every iteration)
void LowerUnoptimized(CString str)
{
    for (int i = 0; i < strlen(str); ++i) {
        str[i] = tolower(str[i]);
    }
}

// Lowercase a C-style string (optimized - calls strlen() once)
void LowerOptimized(CString str)
{
    const size_t length = strlen(str);
    for (int i = 0; i < length; ++i) {
        str[i] = tolower(str[i]);
    }
}

// Lowercase a std::string (unoptimized - calls size() every iteration)
void LowerUnoptimizedStr(string& str)
{
    for (int i = 0; i < str.size(); ++i) {
        str[i] = tolower(str[i]);
    }
}

// Lowercase a std::string (optimized - calls size() once)
void LowerOptimizedStr(string& str)
{
    const size_t length = str.size();
    for (int i = 0; i < length; ++i) {
        str[i] = tolower(str[i]);
    }
}

int main()
{
    const int iterations = 1'000'000;
    const string longText = "HELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLO";

    // Allocate C-style strings safely
    auto cStr1 = std::make_unique<char[]>(longText.size() + 1);
    auto cStr2 = std::make_unique<char[]>(longText.size() + 1);
    strcpy_s(cStr1.get(), longText.size() + 1, longText.c_str());
    strcpy_s(cStr2.get(), longText.size() + 1, longText.c_str());

    string stdStr1 = longText;
    string stdStr2 = longText;

    // Benchmark C-style strings
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i) {
        LowerUnoptimized(cStr1.get());
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsedUnoptimized = end - start;

    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i) {
        LowerOptimized(cStr2.get());
    }
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsedOptimized = end - start;

    // Benchmark std::string
    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i) {
        LowerUnoptimizedStr(stdStr1);
    }
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsedUnoptimizedStr = end - start;

    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i) {
        LowerOptimizedStr(stdStr2);
    }
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsedOptimizedStr = end - start;

    // Print results in a clean table format
    cout << fixed << setprecision(6); // Ensure consistent decimal places
    cout << "+------------------------+----------------+\n";
    cout << "| Test Case              | Time (seconds) |\n";
    cout << "+------------------------+----------------+\n";
    cout << "| C-string (Unoptimized) | " << setw(14) << elapsedUnoptimized.count() << " |\n";
    cout << "| C-string (Optimized)   | " << setw(14) << elapsedOptimized.count() << " |\n";
    cout << "| std::string (Unopt.)   | " << setw(14) << elapsedUnoptimizedStr.count() << " |\n";
    cout << "| std::string (Optimized)| " << setw(14) << elapsedOptimizedStr.count() << " |\n";
    cout << "+------------------------+----------------+\n";

    return 0;
}
