#include <chrono>
#include <iostream>
#include <set>
#include <string>

#include "helper_lib.hpp"

std::multiset<std::string> names;

std::string nameFromIdx(int idx)
{
    return "name";
}

void log(std::chrono::time_point<std::chrono::system_clock> time, std::string val)
{
    std::cout << val << std::endl;
}

template<typename T>
void logAndAdd(T &&name)
{
    auto now = std::chrono::system_clock::now();
    log(now, "logAndAdd");
    names.emplace(std::forward<T>(name));
}

void logAndAdd(int idx)
{
    auto now = std::chrono::system_clock::now();
    log(now, "logAndAdd");
    names.emplace(nameFromIdx(idx));
}

class Person : public LifecycleLogger
{
public:
    template<typename T>
    explicit Person(T &&n)
        : LifecycleLogger("Person")
        , name(std::forward<T>(n))
    {}

    explicit Person(int idx)
        : LifecycleLogger("Person")
        , name(nameFromIdx(idx))
    {}

private:
    std::string name;
};

int main()
{
    std::string petName("Darla");
    logAndAdd(petName);
    logAndAdd(std::string("Persephone"));
    logAndAdd("Patty Dog");
    logAndAdd(22);

    // Note, works only with const!
    const Person p("Nancy");
    auto cloneOfP(p);
}
