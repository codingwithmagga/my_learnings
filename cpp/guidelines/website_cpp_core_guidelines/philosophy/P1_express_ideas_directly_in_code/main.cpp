#include <chrono>
#include <iostream>

using namespace std::chrono_literals;

class Date {
public:
    std::chrono::month month() const // do
    {
        return m_month;
    }
    // int month();          // don't

private:
    std::chrono::month m_month = std::chrono::January;
};

struct Distance {
    double value;
    explicit Distance(double d)
        : value(d)
    {
    }
};

struct Speed {
    double value;
    explicit Speed(double s)
        : value(s)
    {
    }
};

Distance operator"" _m(long double d) { return Distance(static_cast<double>(d)); }

Speed operator/(Distance d, std::chrono::duration<double> t) { return Speed(d.value / t.count()); }

void change_speed(Speed s) { std::cout << "Speed: " << s.value << " m/s\n"; }

int main()
{
    Date testDate;

    std::cout << "Month: " << testDate.month() << std::endl;

    // change_speed(2.3); // error: no unit
    change_speed(23.0_m / 10s); // meters per second

    return 0;
}
