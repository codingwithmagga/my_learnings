#include <execution>
#include <gsl/gsl>
#include <iostream>

using namespace std;

struct Point {
    int x;
    int y;
};

// Bad:
void drawLine(int, int, int, int) { }

// Better:
void drawLine(Point, Point) { }

int main()
{
    vector<int> v { 1, 2, 3, 4 };
    int y = 2;

    // Bad
    gsl::index i = 0;
    while (i < v.size()) {
        v[i] += y;
        ++i;
    }

    // Better
    for (auto& x : v) {
        x += y;
    }

    // Even better, if execution order does not matter (and v is large)
    for_each(std::execution::par, v.begin(), v.end(), [&y](int& x) { x += y; });

    for (const auto& x : v) {
        std::cout << x << endl;
    }
    return 0;
}
