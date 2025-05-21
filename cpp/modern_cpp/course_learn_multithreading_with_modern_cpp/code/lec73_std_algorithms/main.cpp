#include <execution>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main()
{
    vector<int> v { 1, 2, 3, 4, 5 };

    auto sum = accumulate(v.begin(), v.end(), 0);
    auto sumPara = reduce(std::execution::par, v.begin(), v.end(), 0);

    cout << "sum: " << sum << endl;
    cout << "sumPara: " << sumPara << endl;

    vector<int> destPartSum(v.size());
    vector<int> destInclScan(v.size());
    partial_sum(v.begin(), v.end(), destPartSum.begin());
    inclusive_scan(std::execution::par, v.begin(), v.end(), destInclScan.begin());

    for (const auto& val : destPartSum) {
        cout << val << ", ";
    }
    cout << endl;

    for (const auto& val : destInclScan) {
        cout << val << ", ";
    }
    cout << endl;

    return 0;
}
