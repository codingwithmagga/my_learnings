#include <iostream>
#include <source_location>

#include <boost/type_index.hpp>

using namespace boost::typeindex;

template <typename T>
void printT(T &&param)
{
    std::cout << std::source_location::current().function_name() << std::endl;
    std::cout << "Type of param: " << type_id_with_cvr<decltype(param)>().pretty_name() << std::endl;
}

template <typename T>
T &&forwardImpl(std::remove_reference_t<T> &param)
{
    std::cout << std::source_location::current().function_name() << std::endl;
    std::cout << "Type of param: " << type_id_with_cvr<decltype(param)>().pretty_name() << std::endl;

    return static_cast<T &&>(param);
}

template <typename T>
void f(T &&fParam)
{
    printT(forwardImpl<T>(fParam));
}

class Widget
{
};

Widget widgetFactory()
{
    return Widget{};
}

template <typename T>
class WidgetT
{
public:
    WidgetT(T &&val) : x(std::forward<T>(val)) {}

    typedef T &&RvalueRefToT;
    RvalueRefToT x;
};

int main()
{

    Widget w;
    f(w);

    std::cout << "\n";

    f(widgetFactory());

    std::cout << "\n";

    auto &&w1 = w;
    auto &&w2 = widgetFactory();

    std::cout << "Type of w1: " << type_id_with_cvr<decltype(w1)>().pretty_name() << std::endl;
    std::cout << "Type of w2: " << type_id_with_cvr<decltype(w2)>().pretty_name() << std::endl
              << std::endl;

    int v = 1;
    WidgetT<int> wT{1};
    WidgetT<int &> wRT{v};
    std::cout << "Type of w<int>.x: " << type_id_with_cvr<decltype(wT.x)>().pretty_name() << std::endl;
    std::cout << "Type of w<int&>.x: " << type_id_with_cvr<decltype(wRT.x)>().pretty_name() << std::endl;
}
