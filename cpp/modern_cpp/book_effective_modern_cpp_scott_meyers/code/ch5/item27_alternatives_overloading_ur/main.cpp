#include <chrono>
#include <iostream>
#include <set>
#include <string>
#include <type_traits>

std::multiset<std::string> names;
void log(std::chrono::time_point<std::chrono::system_clock> time, std::string val)
{
    std::cout << val << std::endl;
}

std::string nameFromIdx(int idx)
{
    return "NameIdx " + std::to_string(idx);
}

template<typename T>
void logAndAdd(T &&name);

template<typename T>
void logAndAddImpl(T &&name, std::false_type)
{
    auto now = std::chrono::system_clock::now();
    log(now, name);
    names.emplace(std::forward<T>(name));
}

void logAndAddImpl(int idx, std::true_type)
{
    logAndAdd(nameFromIdx(idx));
}

template<typename T>
void logAndAdd(T &&name)
{
    logAndAddImpl(std::forward<T>(name), std::is_integral<std::remove_reference_t<T>>());
}

class Person
{
public:
    template<typename T,
             typename = std::enable_if_t<!std::is_base_of<Person, std::decay_t<T>>::value
                                         && !std::is_integral<std::remove_reference_t<T>>::value>>
    explicit Person(T &&n)
        : name(std::forward<T>(n))
    {
        static_assert(std::is_constructible<std::string, T>::value,
                      "Parameter n can't be used to construct a std::string.");
        std::cout << "Create person " << name << " from ur ctor \n";
    }

    explicit Person(int idx)
        : name(nameFromIdx(idx))
    {
        std::cout << "Create person " << name << " from int ctor \n";
    }

    Person(const Person &other)
        : name(other.name)
    {
        std::cout << "Create person " << name << " from copy ctor \n";
    }

private:
    std::string name;
};

int main()
{
    {
        std::string petName("Darla");
        logAndAdd(petName);
        logAndAdd(std::string("Persephone"));
        logAndAdd("Patty Dog");
        logAndAdd(22);
    }
    std::cout << std::endl;
    {
        Person p("Nancy");

        auto cloneOfP(p);

        // Person up(u"Konrad Zuse");
    }
}
