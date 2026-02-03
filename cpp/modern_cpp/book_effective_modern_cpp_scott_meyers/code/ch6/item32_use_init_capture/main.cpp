#include <memory>
#include <iostream>
#include <vector>
#include <functional>

class Widget
{
public:
    bool isValidated() const { return true; };

    bool isProcessed() const { return true; };

    bool isArchived() const { return false; };

private:
};

class IsValAndArch
{
public:
    using DataType = std::unique_ptr<Widget>;
    explicit IsValAndArch(DataType &&ptr) : pw(std::move(ptr)) {}
    bool operator()() const { return pw->isValidated() && pw->isArchived(); }

private:
    DataType pw;
};

int main()
{
    {
        auto pw = std::make_unique<Widget>();
        auto func = [pw = std::move(pw)]
        {
            return pw->isProcessed() && pw->isArchived();
        };

        auto func2 = [pw = std::make_unique<Widget>()]
        {
            return pw->isProcessed() && pw->isValidated();
        };
        auto func3 = IsValAndArch(std::make_unique<Widget>());

        std::cout << std::boolalpha << "Widget is processed and archived: " << func() << "\n";
        std::cout << std::boolalpha << "Widget is valid and processed: " << func2() << "\n";
        std::cout << std::boolalpha << "Widget is validated and archived: " << func3() << "\n";
    }

    std::cout << "\n";

    {
        std::vector<int> data{1, 2, 3, 4, 5};
        auto func = [data = std::move(data)]
        {
            for (const auto &elem : data)
            {
                std::cout << elem << " ";
            }
            std::cout << "\n";
        };

        std::vector<int> data2{1, 2, 3};
        auto func2 = std::bind([](const std::vector<int> &data)
                               { for (const auto &elem : data)
        {
            std::cout << elem << " ";
        }
        std::cout << "\n"; }, std::move(data2));

        func();
        func2();
    }

    return 0;
}
