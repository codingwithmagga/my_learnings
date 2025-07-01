#include <iostream>

class Widget {
public:
    Widget()
    {
        std::cout << "Widget() called\n\n";
    }

    Widget(int i, bool b)
    {
        std::cout << "Widget(int i, bool b) called\n\n";
    }

    Widget(int i, double d)
    {
        std::cout << "Widget(int i, double d) called\n\n";
    }

    Widget(std::string str1, std::string str2)
    {
        std::cout << "Widget(std::string str1, std::string str2) called\n\n";
    }

    Widget(std::initializer_list<long double> il)
    {
        std::cout << "Widget(std::initializer_list<long double> il) called\n\n";
    }

    Widget(const Widget& rhs)
    {
        std::cout << "Widget(const Widget& rhs) called\n\n";
    }

    Widget(const Widget&& rhs)
    {
        std::cout << "Widget(const Widget&& rhs) called\n\n";
    }

    operator float() const
    {
        std::cout << "float() used\n";
        return 1.0;
    }
};

int main()
{
    std::cout << "Call Widget w1(10, true): \n";
    Widget w1(10, true);

    std::cout << "Call Widget w2 { 10, true }: \n";
    Widget w2 { 10, true };

    std::cout << "Call Widget w3(10, 5.0): \n";
    Widget w3(10, 5.0);

    std::cout << "Call Widget w4 { 10, 5.0 }: \n";
    Widget w4 { 10, 5.0 };

    std::cout << "Call Widget w5(w4): \n";
    Widget w5(w4);

    std::cout << "Call Widget w6{w4}: \n";
    Widget w6 { w4 };

    std::cout << "Call Widget w7(std::move(w4)): \n";
    Widget w7(std::move(w4));

    std::cout << "Call Widget w8{std::move(w1)}: \n";
    Widget w8 { std::move(w1) };

    std::cout << "Call Widget w9{}: \n";
    Widget w9 {};

    std::cout << "Call Widget w10 { \"10\", \"11.0\" }: \n";
    Widget w10 { "10", "11.0" };

    return 0;
}
