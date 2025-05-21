#include <execution>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v1 { 1, 2, 3, 4, 5 };
    vector<int> v2 { 5, 10, 12, 4, -2 };

    auto biggestError = transform_reduce(execution::par, v1.begin(), v1.end(), v2.begin(), 0, [](int a, int b) { return max(a, b); }, [](int a, int b) { return abs(a - b); });
    cout << "biggestError " << biggestError << endl;

    return 0;
}
