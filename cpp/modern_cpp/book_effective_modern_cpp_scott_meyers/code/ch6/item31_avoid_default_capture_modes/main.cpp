#include <iostream>
#include <vector>
#include <functional>

using FilterContainer = std::vector<std::function<bool(int)>>;
FilterContainer filters;

void addFilterFree(const int divisor = 4)
{
    filters.push_back([divisor = divisor](int value)
                      { return (value % divisor) == 0; });
}

class Widget
{
public:
    void addFilter() const
    {
        filters.push_back([divisor = divisor](int value)
                          { return (value % divisor) == 0; });
    }

private:
    int divisor = 5;
};

int main()
{
    {
        Widget w;
        w.addFilter();
        addFilterFree();

        for (const auto &filter : filters)
        {
            std::cout << "Filter 15: " << filter(15) << "\n";
            std::cout << "Filter 16: " << filter(16) << "\n"
                      << "\n";
        }
    }

    addFilterFree(12);

    for (const auto &filter : filters)
    {
        std::cout << "Filter 15: " << filter(15) << "\n";
        std::cout << "Filter 16: " << filter(16) << "\n"
                  << "\n";
    }

    return 0;
}
