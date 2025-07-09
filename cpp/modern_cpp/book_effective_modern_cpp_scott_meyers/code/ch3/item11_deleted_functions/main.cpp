#include <iostream>

#include <boost/type_index.hpp>

using namespace boost::typeindex;

class NoCopy {
public:
    NoCopy()
    {
        std::cout << "NoCopy default ctor." << std::endl;
    }

    NoCopy(const NoCopy&) = delete;
    NoCopy& operator=(const NoCopy&) = delete;
};

bool isLucky(int number)
{
    std::cout << "Check if " << number << " is lucky." << std::endl;
    return true;
};

bool isLucky(char) = delete;
bool isLucky(bool) = delete;
bool isLucky(double) = delete;

class Widget {
public:
    template <typename T>
    void processPointer(T* ptr)
    {
        std::cout << "Process pointer of type " << type_id_with_cvr<decltype(ptr)>().pretty_name() << std::endl;
    }
};

template <>
void Widget::processPointer<void>(void*) = delete;
template <>
void Widget::processPointer<char>(char*) = delete;
template <>
void Widget::processPointer<const void>(const void*) = delete;
template <>
void Widget::processPointer<const char>(const char*) = delete;

int main()
{
    NoCopy noCopy;

    // These are all deleted
    // auto noCopy2 = noCopy;
    // auto noCopy3(noCopy);

    isLucky(1);

    // These are all deleted
    // isLucky("1");
    // isLucky(true);
    // isLucky(0.1);
    // isLucky(0.1f);

    Widget w;
    int x = 5;
    w.processPointer(&x);

    // These are all deleted
    // void* ptr = nullptr;
    // w.processPointer(ptr);
    // const char* str = "Test string";
    // w.processPointer(str);

    return 0;
}
