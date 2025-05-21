#include <algorithm>
#include <execution>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main()
{
    vector<int> v1 { 1, 2, 3, 4, 5 };
    vector<int> v2 { 5, 10, 12, 4, -2 };

    vector<int> output(v1.size());

    transform(v1.begin(), v1.end(), v2.begin(), output.begin(), [](const int i, const int j) { return i + j; });

    for (const auto& val : output) {
        cout << val << ", ";
    }
    cout << endl;

    auto innerProd = inner_product(v1.begin(), v1.end(), v2.begin(), 0);
    cout << "innerProd " << innerProd << endl;

    auto innerProdTF = transform_reduce(execution::par, v1.begin(), v1.end(), v2.begin(), 0);
    cout << "innerProdTF " << innerProdTF << endl;

    return 0;
}
