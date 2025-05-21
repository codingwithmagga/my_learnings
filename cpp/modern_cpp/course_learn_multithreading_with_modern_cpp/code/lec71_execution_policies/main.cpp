#include <algorithm>
#include <chrono>
#include <execution>
#include <iostream>
#include <vector>

using namespace std;
namespace se = std::execution;

template <class C>
void run(C method)
{

    std::vector<int> vec(50'000'000);
    int count = 0;
    std::iota(vec.begin(), vec.end(), 1);

    auto start = std::chrono::high_resolution_clock::now();
    std::for_each(method, vec.begin(), vec.end(),
        [&count](int& x) { x *= 2; });
    auto end = std::chrono::high_resolution_clock::now();

    // Calculate the duration
    std::chrono::duration<double> duration = end - start;

    cout << vec.back() << endl;

    // Output the duration in seconds
    std::cout << "Function execution time: " << duration.count() << " seconds" << std::endl;
}

int main()
{
    cout << "seq: " << endl;
    run(se::seq);
    cout << endl;

    cout << "vec: " << endl;
    run(se::unseq);
    cout << endl;

    cout << "par: " << endl;
    run(se::par);
    cout << endl;

    cout << "vec par: " << endl;
    run(se::par_unseq);

    return 0;
}
