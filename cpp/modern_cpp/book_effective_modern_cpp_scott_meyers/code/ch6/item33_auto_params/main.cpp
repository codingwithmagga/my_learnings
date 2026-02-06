#include <iostream>
#include <string>
#include <utility>

struct Widget
{
    std::string name;
    Widget(std::string n) : name(std::move(n)) { std::cout << "ctor\n"; }
    Widget(const Widget &w) : name(w.name) { std::cout << "copy\n"; }
    Widget(Widget &&w) noexcept : name(std::move(w.name)) { std::cout << "move\n"; }
};

const Widget &normalize(const Widget &w)
{
    std::cout << "normalize(const&)\n";
    return w;
}

Widget normalize(Widget &&w)
{
    std::cout << "normalize(&&)\n";
    for (auto &c : w.name)
        c = std::toupper(static_cast<unsigned char>(c));
    return w;
}

Widget normalize(Widget &&w1, Widget &&w2)
{
    std::cout << "normalize multi(&&)\n";
    for (auto &c : w1.name)
        c = std::toupper(static_cast<unsigned char>(c));
    for (auto &c : w2.name)
        c = std::toupper(static_cast<unsigned char>(c));

    w1.name += "+" + w2.name;
    return w1;
}

void func(const Widget &w)
{
    std::cout << "func(const&): " << w.name << "\n";
}

void func(Widget &&w)
{
    std::cout << "func(&&): " << w.name << "\n";
}

auto f = [](auto &&param)
{
    return func(normalize(std::forward<decltype(param)>(param)));
};

auto fMulti = [](auto &&...params)
{
    return func(normalize(std::forward<decltype(params)>(params)...));
};

int main()
{
    std::cout << "---- rvalue ----\n";
    f(Widget{"alpha"});

    std::cout << "\n---- lvalue ----\n";
    Widget w{"beta"};
    f(w);

    std::cout << "\n---- multi (rvalue) ----\n";
    fMulti(Widget{"gamma"}, Widget{"delta"});

    return 0;
}