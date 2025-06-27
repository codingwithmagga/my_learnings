#include <iostream>
#include <vector>

#include <boost/type_index.hpp>

using namespace boost::typeindex;

template <typename T>
class TD;

template <typename T>
void f_typeId(const T& param)
{
    std::cout << "T =     " << typeid(T).name() << '\n';
    std::cout << "param = " << typeid(param).name() << '\n';
}

template <typename T>
void f_boostType(const T& param)
{
    std::cout << "T =     " << type_id_with_cvr<T>().pretty_name() << '\n';
    std::cout << "param = " << type_id_with_cvr<decltype(param)>().pretty_name() << '\n';
}

class Widget {
};

std::vector<Widget> createVec()
{
    std::vector<Widget> vec { Widget {}, Widget {}, Widget {} };
    return vec;
}

int main()
{
    const int theAnswer = 42;

    auto x = theAnswer;
    auto y = &theAnswer;

    // Print the type of x and y as a compiler error if commented out
    // TD<decltype(x)> xType;
    // TD<decltype(y)> yType;

    std::cout << typeid(x).name() << '\n';
    std::cout << typeid(y).name() << "\n\n";

    const auto vw = createVec();
    if (!vw.empty()) {
        f_typeId(&vw[0]);
        std::cout << std::endl;
        f_boostType(&vw[0]);
    }

    return 0;
}
