
#include <iostream>

template <typename T>
class Printer
{
public:
    void print()
    {
        std::cout << "I'm Printer<T>" << "\n";
    }
};

template <>
class Printer<int>
{
public:
    void print()
    {
        std::cout << "I'm specialized Printer<int>" << "\n";
    }
};

template <typename T>
class Printer<T *>
{
public:
    void print()
    {
        std::cout << "I'm partly specialized Printer<T*>" << "\n";
    }
};

int main()
{
    Printer<double> pr1;
    pr1.print();

    Printer<int> pr2;
    pr2.print();

    Printer<double *> pr3;
    pr3.print();
}
/*
    Questions :

    1. What is the difference between full specialization and partial specialization?
        For a full specialization there is only exactly one type which fits (here int)-
        For a partial specialization there are multiple fitting types, here all pointers: int*, double*, const char*, ...

    2. Which version would be selected for these types?
    * `Printer<double>` -> General version Printer<T>
    * `Printer<int>` -> full specialization Printer<int>
    * `Printer<char*>` -> partial specialization Printer<T*>

    3. Why are partial specializations especially important for **class templates**, but not for **function templates**?
        Function templates uses overloading and template argument deduction.

*/