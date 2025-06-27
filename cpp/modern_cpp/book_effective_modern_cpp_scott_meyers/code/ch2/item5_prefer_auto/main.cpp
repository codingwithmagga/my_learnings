#include <iostream>
#include <iterator>
#include <vector>

template <typename It>
void dwim(It b, It e)
{
    while (b != e) {
        typename std::iterator_traits<It>::value_type currValue = *b;
        std::cout << currValue << ", ";
        ++b;
    }

    std::cout << std::endl;
}

template <typename It>
void dwim_auto(It b, It e)
{
    while (b != e) {
        auto currValue = *b;
        std::cout << currValue << ", ";
        ++b;
    }

    std::cout << std::endl;
}

auto derefLess = [](const auto& p1, const auto& p2) { return *p1 < *p2; };

int main()
{

    std::vector<int> v { 1, 2, 3, 4 };
    dwim(v.begin(), v.end());
    dwim_auto(v.begin(), v.end());
    std::cout << std::endl;

    auto val1 = std::make_unique<int>(5);
    auto val2 = std::make_unique<int>(7);

    std::cout << std::boolalpha << "Is *val1 smaller than *val2: " << derefLess(val1, val2) << std::endl;

    return 0;
}
