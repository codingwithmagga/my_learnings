#include <algorithm>
#include <execution>
#include <iostream>
#include <vector>

using namespace std;

int main()
{

    vector<int> v { 1, 23, 5, 6, 2, 6 };

    try {
        for_each(std::execution::par, v.begin(), v.end(), [](int& x) {
            x *= 2;
            // throw(std::out_of_range("Error"));
        });
    } catch (std::exception& e) {
        cout << e.what() << endl;
    }

    for (const auto& e : v) {
        cout << e << ", ";
    }
    cout << endl;

    return 0;
}
