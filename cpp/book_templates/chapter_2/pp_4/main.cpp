#include <iostream>

template <typename T>
class Value;

template <typename T>
std::ostream &operator<<(std::ostream &os, const Value<T> &v);

template <typename T>
class Value
{
private:
    T val;

public:
    Value(T v) : val(v) {}

    friend std::ostream &operator<< <>(std::ostream &os, const Value &v);
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const Value<T> &v)
{
    return os << v.val;
}

int main()
{
    Value v(42);
    Value w(std::string("hello"));

    std::cout << "v: " << v << "\n";
    std::cout << "w: " << w << "\n";
}
/*
    Questions :

    1. Why might this syntax only become convenient starting with C++17?
       Because of CTAD (Class Template Argument Deduction), now the template parameter can be ommitted
       => Value v(42);

    2. What is the difference between:
        * `Value<int> v(42);`-> explicit
        * `Value v(42);`-> T will be deduced automatically
        Less writing, more like auto.

    3. Why are friends in template classes often trickier than in ordinary classes?
        Name deduction (ADL)
        Every template instance is a distinct type
        Friend can:
            only regard to one instance
            or the whole template

*/