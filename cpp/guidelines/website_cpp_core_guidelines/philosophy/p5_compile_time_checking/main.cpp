#include <iostream>

using namespace std;

void bad_check()
{
    int bits = 0;
    for (int i = 1; i; i <<= 1)
        ++bits;
    if (bits < 32)
        cerr << "int too small\n";
}

int main()
{
    bad_check();

    // do: compile-time check
    static_assert(sizeof(int) >= 4, "int too small!");

    // Better: Use int32_t
    int32_t myInt = 42;
    cout << "myInt is big enough.\n";

    // For span usage check p4_type_safe_program

    return 0;
}
