#include <iostream>

using namespace std;

int main()
{
    auto ptr = make_shared<int>(10);

    *ptr = *ptr + 2;

    auto copyptr = ptr;

    cout << "val " << *ptr << endl;
    cout << "val copy " << *copyptr << endl;

    return 0;
}
