
#include <iostream>
#include <chrono>
#include <vector>
#include <array>
#include <algorithm> // std::fill

class Widget
{
public:
    explicit Widget(double val = 0.0) : m_val(val) {}

private:
    double m_val;
};

int main()
{
    using Clock = std::chrono::steady_clock;

    constexpr std::size_t N = 100'000; // 10^5

    // =========================
    // Vector section (stack-managed)
    // =========================
    std::vector<Widget> vw1;
    vw1.reserve(N);
    vw1.insert(vw1.end(), N, Widget{2.4});

    // Measure vector copy
    auto start = Clock::now();
    std::vector<Widget> vw2 = vw1; // deep copy
    auto end = Clock::now();
    auto elapsed = (end - start).count(); // raw tick count
    std::cout << "Copy vec cycles:  " << elapsed << "\n";

    // Measure vector move
    start = Clock::now();
    std::vector<Widget> vw3 = std::move(vw1); // O(1) move
    end = Clock::now();
    elapsed = (end - start).count();
    std::cout << "Move vec cycles:  " << elapsed << "\n";

    // =========================
    // Array section (stack-managed std::array)
    // =========================
    std::array<Widget, N> aw1;
    std::fill(aw1.begin(), aw1.end(), Widget{2.4});

    // Measure array copy (O(N))
    start = Clock::now();
    std::array<Widget, N> aw2 = aw1; // element-wise copy
    end = Clock::now();
    elapsed = (end - start).count();
    std::cout << "Copy array cycles: " << elapsed << "\n";

    // Measure array move (still O(N))
    start = Clock::now();
    std::array<Widget, N> aw3 = std::move(aw1); // element-wise move
    end = Clock::now();
    elapsed = (end - start).count();
    std::cout << "Move array cycles: " << elapsed << "\n";

    return 0;
}
