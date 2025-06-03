#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void f_bad(const char* name)
{
    FILE* input = fopen(name, "r");
    // ...
    if (true)
        return; // bad: if something == true, a file handle is leaked
    // ...
    fclose(input);
}

void f_good(const char* name)
{
    ifstream input { name };

    if (!input.is_open()) {
        cerr << "Failed to open file: " << name << endl;
        return; // No leak; 'input' destructor closes the file automatically
    }

    string line;
    while (getline(input, line)) { // Read line-by-line
        cout << line << endl; // Print to console
    }

    if (true)
        return; // OK: no leak

    // File is automatically closed when 'input' goes out of scope
}

int main()
{
    // f:bad(exmaple.txt)

    cout << "Reading from 'example.txt':" << endl
         << endl;
    f_good(string("example.txt").c_str());

    return 0;
}
