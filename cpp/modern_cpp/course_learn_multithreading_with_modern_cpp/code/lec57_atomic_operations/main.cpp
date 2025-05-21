#include <iostream>

using namespace std;

int main()
{
    atomic<int> x = 0;
    auto y = 5;

    cout << "start val: " << x << " " << y << endl;

    x.store(34);

    cout << "after store: " << x << " " << y << endl;

    cout << "using load: " << x.load() << endl;
    cout << "using exchange: " << x.exchange(y) << endl;

    cout << "after exchange: " << x << " " << y << endl;

    return 0;
}
