#include <iostream>
#include <span>

using namespace std;

void increment1(int* p, int n) // bad: error-prone
{
    for (int i = 0; i < n; ++i)
        ++p[i];
}

void increment2(span<int> p)
{
    for (int& x : p)
        ++x;
}

void use(int m)
{
    const int n = 10;
    int a[n] = {};
    // increment1(a, m); // maybe typo, maybe m <= n is supposed
    // increment2({ a, m }); // but assume that m == 20

    cout << "bf: ";
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    increment2(a);

    cout << "af: ";
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    use(2);
    return 0;
}
