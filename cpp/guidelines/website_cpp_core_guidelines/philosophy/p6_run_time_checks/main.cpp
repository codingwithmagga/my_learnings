#include <iostream>
#include <vector>

using namespace std;

const int globalSize = 5;

// Assume this is separately compiled, possibly dynamically loaded
/*extern*/ void f1(int* p)
{
    cout << "f1 ";
    for (int i = 0; i < globalSize; ++i) {
        cout << p[i] << " ";
    }
    cout << endl
         << endl;
}

// Assume this is separately compiled, possibly dynamically loaded
/*extern*/ void f2(int* p, int n)
{
    cout << "f2 ";
    for (int i = 0; i < n; ++i) {
        cout << p[i] << " ";
    }
    cout << endl
         << endl;
}

// Better:
void f3(vector<int> v)
{
    cout << "f ";
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl
         << endl;
}

// Bad
void g1(int n)
{
    f1(new int[n]);
}

// Also bad
void g2(int n)
{
    f2(new int[n], n);
}

// Better
void g3(int n)
{
    vector<int> v(n);

    for (int i = 0; i < n; ++i) {
        v[i] = i;
    }
    f3(v);
}

int main()
{
    g1(5);
    g2(5);
    g3(5);

    return 0;
}
