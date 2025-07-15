#include <array>
#include <iostream>

// C++14, not possible in C++11 (loops forbidden in constexpr functions)
constexpr int pow(int base, int exp) noexcept
{
    auto result = 1;
    for (int i = 0; i < exp; ++i)
        result *= base;
    return result;
}

class Point {
public:
    constexpr Point(double xVal = 0, double yVal = 0) noexcept
        : x(xVal)
        , y(yVal)
    {
    }
    constexpr double xValue() const noexcept { return x; }
    constexpr double yValue() const noexcept { return y; }

    // Setter functions can only be written constexpr in C++14
    constexpr void setX(double newX) noexcept { x = newX; }
    constexpr void setY(double newY) noexcept { y = newY; }

private:
    double x,
        y;
};

constexpr Point midpoint(const Point& p1, const Point& p2) noexcept
{
    return { (p1.xValue() + p2.xValue()) / 2,
        (p1.yValue() + p2.yValue()) / 2 };
}
constexpr Point reflection(const Point& p) noexcept
{
    Point result;
    result.setX(-p.xValue());
    result.setY(-p.yValue());
    return result;
}

int main()
{
    {
        constexpr auto arraySize = 10;
        std::array<int, arraySize> data;

        std::cout << "Length data: " << data.size() << "\n";
    }

    {
        constexpr auto numConds = 5;
        std::array<int, pow(3, numConds)> results;

        std::cout << "Length results: " << results.size() << "\n";
    }

    {
        constexpr Point p1(9.4, 27.7);
        constexpr Point p2(28.8, 5.3);

        constexpr auto mid = midpoint(p1, p2);
        std::cout << "mid: " << mid.xValue() << ", " << mid.yValue() << "\n";

        constexpr auto reflectedMid = reflection(mid);
        std::cout << "reflectedMid: " << reflectedMid.xValue() << ", " << reflectedMid.yValue() << "\n";
    }
}
