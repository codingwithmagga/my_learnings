#include <list>

template <typename T>
using MyAlloc = std::allocator<T>;

// alias declaration
template <typename T>
using MyAllocListAlias = std::list<T, MyAlloc<T>>;

template <typename T>
class WidgetAlias {

public:
    void add(T val)
    {
        list.push_back(val);
    }

private:
    MyAllocListAlias<T> list;
};

// typedef
template <typename T>
struct MyAllocListTypedef {
    typedef std::list<T, MyAlloc<T>> type;
};

template <typename T>
class WidgetTypedef {
public:
    void add(T val)
    {
        list.push_back(val);
    }

private:
    typename MyAllocListTypedef<T>::type list;
};

int main()
{
    WidgetAlias<int> wAlias;
    wAlias.add(2);
    wAlias.add(3);

    WidgetTypedef<int> wTypedef;
    wTypedef.add(2);
    wTypedef.add(3);

    return 0;
}
