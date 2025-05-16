#include <gsl/narrow>
#include <iostream>
#include <span>
#include <variant>

using namespace std;

union Data {
    int i;
    float f;
    char str[20];
};

void unionVsVariant()
{
    Data dataUnion;
    std::variant<int, float, std::string> dataVar;

    dataUnion.i = 42;
    dataVar = 42;
    std::cout << "dataUnion.i = " << dataUnion.i << std::endl;
    std::cout << "dataVar int = " << std::get<int>(dataVar) << std::endl;

    dataUnion.f = 3.14f;
    dataVar = 3.14f;
    std::cout << "dataUnion.f = " << dataUnion.f << std::endl;
    std::cout << "dataVar f   = " << std::get<float>(dataVar) << std::endl;

    strcpy_s(dataUnion.str, "Hello");
    dataVar = "Hello";
    std::cout << "dataUnion.str = " << dataUnion.str << std::endl;
    std::cout << "dataVar str   = " << std::get<string>(dataVar) << std::endl;

    // Accessing the wrong type is undefined behavior!
    // std::cout << data.i << std::endl;

    if (auto* pInt = std::get_if<int>(&dataVar)) {
        std::cout << "Currently holds int: " << *pInt << std::endl;
    } else {
        std::cout << "Does not hold an int." << std::endl;
    }

    // Try to access the wrong type? Throws std::bad_variant_access
    try {
        std::cout << std::get<int>(dataVar) << std::endl; // Throws (last was string)
    } catch (const std::bad_variant_access& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void print(int arr[], size_t size) // Actually `int* arr` (array decay)
{
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void print(std::span<const int> arr)
{
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

// The same example can beused for range errors!
void arrayDecayVsSpan()
{
    int data[] = { 1, 2, 3 };
    print(data, 3);
    print(data);
}

struct Distance {
    double value;
    explicit Distance(double d)
        : value(d)
    {
    }
};

Distance operator"" _m(long double d) { return Distance(gsl::narrow_cast<double>(d)); }

void narrowCast()
{
    Distance d = 23.0_m;
    std::cout << "Distance: " << d.value << std::endl;

    try {
        float f = 3.1415f;
        int i = gsl::narrow<int>(f);
    } catch (...) {
        std::cout << "Catched narrow conversion issue!" << std::endl;
    }
}

int main()
{
    std::cout << "union vs. variant: " << std::endl
              << std::endl;
    unionVsVariant();
    std::cout << "\n------------------------------------- \n \n";

    std::cout << "array decay vs gsl span: " << std::endl;
    arrayDecayVsSpan();
    std::cout << "\n------------------------------------- \n \n";

    std::cout << "Narrow cast: " << std::endl;
    narrowCast();

    return 0;
}
