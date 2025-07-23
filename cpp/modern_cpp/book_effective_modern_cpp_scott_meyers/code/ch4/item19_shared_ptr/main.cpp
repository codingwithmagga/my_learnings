#include <iostream>
#include <vector>

class Widget;

std::vector<std::shared_ptr<Widget>> processedWidgets;

class Widget : public std::enable_shared_from_this<Widget> {
public:
    template <typename... Ts>
    static std::shared_ptr<Widget> create(Ts&&... params)
    {
        return std::make_shared<Widget>();
    }

    ~Widget()
    {
        std::cout << "Widget destroyed\n";
    }

    void process()
    {
        processedWidgets.emplace_back(shared_from_this());
    }

    // shall be private but then i can't use the custom deleter example here
    Widget()
    {
        std::cout << "Widget created\n";
    }
};

auto customDeleter1 = [](Widget* pw) { std::cout << "Widget deleted using customDeleter1\n"; delete pw; };
auto customDeleter2 = [](Widget* pw) { std::cout << "Widget deleted using customDeleter2\n"; delete pw; };

int main()
{
    std::shared_ptr<Widget> pw1(new Widget, customDeleter1);
    std::shared_ptr<Widget> pw2(new Widget, customDeleter2);

    std::vector<std::shared_ptr<Widget>> vpw { pw1, pw2 };

    pw1->process();
    pw2->process();

    auto pw3 = Widget::create();
    pw3->process();
    auto pw4 = Widget::create();
    pw4->process();

    std::cout << "\n"
              << "processedWidgets size: " << processedWidgets.size() << "\n\n";
}
