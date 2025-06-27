#include <deque>
#include <iostream>
#include <vector>

#include <boost/type_index.hpp>

using namespace boost::typeindex;

class Widget { };

struct Point {
    int x, y;
};

bool f(const Widget& w)
{
    std::cout << "Type of w: " << type_id_with_cvr<decltype(w)>().pretty_name() << std::endl;
    return true;
}

template <typename Container, typename Index>
decltype(auto) authAndAccess(Container&& c, Index i)
{
    // authenticateUser();
    return std::forward<Container>(c)[i];
}

std::deque<std::string> makeStringDeque()
{
    std::deque<std::string> dq;

    for (int i = 0; i < 7; ++i) {
        dq.push_back(std::to_string(i));
    }

    return dq;
}

decltype(auto) f1()
{
    int x = 0;
    return x;
}

decltype(auto) f2()
{
    int x = 0;

    // warning: returning a reference to a local variable!
    return (x);
}

int main()
{
    const int i = 0;
    std::cout << "Type of i: " << type_id_with_cvr<decltype(i)>().pretty_name() << std::endl
              << std::endl;

    Point p { 1, 2 };
    std::cout << "Type of p: " << type_id_with_cvr<decltype(p)>().pretty_name() << std::endl;
    std::cout << "Type of p.x: " << type_id_with_cvr<decltype(p.x)>().pretty_name() << std::endl;
    std::cout << "Type of p.y: " << type_id_with_cvr<decltype(p.y)>().pretty_name() << std::endl
              << std::endl;

    Widget w;
    f(w);
    std::cout << "Type of f: " << type_id_with_cvr<decltype(f)>().pretty_name() << std::endl;
    std::cout << "Type of f(w): " << type_id_with_cvr<decltype(f(w))>().pretty_name() << std::endl
              << std::endl;

    std::vector<int> v { 1, 2, 3 };
    std::cout << "Type of v: " << type_id_with_cvr<decltype(v)>().pretty_name() << std::endl;
    std::cout << "Type of v[0]: " << type_id_with_cvr<decltype(v[0])>().pretty_name() << std::endl
              << std::endl;

    const Widget& cw = w;

    auto myWidget1 = cw;
    decltype(auto) myWidget2 = cw;

    std::cout << "Type of cw: " << type_id_with_cvr<decltype(cw)>().pretty_name() << std::endl;
    std::cout << "Type of myWidget1: " << type_id_with_cvr<decltype(myWidget1)>().pretty_name() << std::endl;
    std::cout << "Type of myWidget2: " << type_id_with_cvr<decltype(myWidget2)>().pretty_name() << std::endl
              << std::endl;

    auto s = authAndAccess(makeStringDeque(), 5);
    std::cout << "Got s: " << s << std::endl
              << std::endl;

    std::cout << "Type of f1(): " << type_id_with_cvr<decltype(f1())>().pretty_name() << std::endl;
    // Works, but note that the return value of f2() is a local variable -> undefined behaviour
    std::cout << "Type of f2(): " << type_id_with_cvr<decltype(f2())>().pretty_name() << std::endl;

    return 0;
}
