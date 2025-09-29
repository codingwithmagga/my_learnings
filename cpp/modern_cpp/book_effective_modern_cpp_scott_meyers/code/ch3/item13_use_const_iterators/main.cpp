#include <iostream>
#include <vector>
#include <algorithm>

void printVec(const std::vector<int> vec)
{
    for (const auto val : vec) {
        std::cout << val << ", ";
    }
    std::cout << "\n";
}

template <typename C, typename V>
void findAndInsert(C& container, const V& targetVal, const V& insertVal)
{
    using std::cbegin;
    using std::cend;

    auto it = std::find(cbegin(container), cend(container), targetVal);
    container.insert(it, insertVal);
}

int main()
{
    {
        std::vector<int> values { 1980, 1983, 2010 };
        std::cout << "Before insertion:\n";
        printVec(values);
        std::cout << "\n";

        auto it = std::find(values.cbegin(), values.cend(), 1983);
        values.insert(it, 1998);
        std::cout << "After insertion:\n";
        printVec(values);
        std::cout << "\n\n";
    }

    {
        std::vector<int> values { 1980, 1983, 2010 };
        std::cout << "Before insertion with template function:\n";
        printVec(values);
        std::cout << "\n";

        findAndInsert(values, 1983, 1998);
        std::cout << "After insertion with template function:\n";
        printVec(values);
    }

    return 0;
}
