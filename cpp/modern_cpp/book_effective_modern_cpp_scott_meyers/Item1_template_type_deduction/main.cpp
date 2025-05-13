#include <array>
#include <iostream>
#include <source_location>

// template <typename T>
// void f(ParamType param);

// Case 1: ParamType is a Reference or Pointer, but not a Universal Reference
template <typename T>
void fc1(T& param)
{
    std::cout << std::source_location::current().function_name() << std::endl;
}

template <typename T>
void fc1_const(const T& param)
{
    std::cout << std::source_location::current().function_name() << std::endl;
}

template <typename T>
void fc1_ptr(T* param)
{
    std::cout << std::source_location::current().function_name() << std::endl;
}

// Case 2: ParamType is a Universal Reference
template <typename T>
void fc2(T&& param)
{
    std::cout << std::source_location::current().function_name() << std::endl;
}

// Case 3: ParamType is Neither a Pointer nor a Reference
template <typename T>
void fc3(T param)
{
    std::cout << std::source_location::current().function_name() << std::endl;
}

// return size of an array as a compile-time constant. (The
// array parameter has no name, because we care only about
// the number of elements it contains.)
template <typename T, std::size_t N>
constexpr std::size_t arraySize(T (&)[N]) noexcept
{
    return N;
}

void someFunc(int, double) { }

int main()
{
    int x = 27;
    const int cx = x;
    const int& rx = x;
    const int* px = &x;
    const char* const ptr = "Fun with pointers";
    const char name[] = "J. P. Briggs";
    const char* ptrToName = name;

    std::cout << "Case 1 ParamType is a Reference or Pointer, but not a Universal Reference" << std::endl;
    fc1(x);
    fc1(cx);
    fc1(rx);

    std::cout << "\nCase 1 with const" << std::endl;
    fc1_const(x);
    fc1_const(cx);
    fc1_const(rx);

    std::cout << "\nCase 1 with ptr" << std::endl;
    fc1_ptr(&x);
    fc1_ptr(px);

    std::cout << "\nCase 2 ParamType is a Universal Reference" << std::endl;
    fc2(x);
    fc2(cx);
    fc2(rx);
    fc2(27);

    std::cout << "\nCase 3 ParamType is Neither a Pointer nor a Reference" << std::endl;
    fc3(x);
    fc3(cx);
    fc3(rx);
    fc3(ptr);
    fc3(name);
    fc3(ptrToName);

    int keyVals[] = { 1, 3, 7, 9, 11, 22, 35 };
    std::array<int, arraySize(keyVals)> mappedVals;
    std::cout << "\nmappedVals size: " << mappedVals.size() << std::endl;

    std::cout << "\nFunction arguments" << std::endl;
    fc3(someFunc);
    fc1(someFunc);

    return 0;
}
