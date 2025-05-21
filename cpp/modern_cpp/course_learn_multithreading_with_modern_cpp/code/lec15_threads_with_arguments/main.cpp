#include <iostream>
#include <string>
#include <thread>

using namespace std;

void hello_world(string& str)
{
    cout << str << "\n";
    str = "new Hello World";
}

void hello_world_move(int&& i)
{
    cout << i << "\n";
}

class FunctorClass {
public:
    void operator()(int i, int j)
    {
        cout << "FunctorClass here " << i + j << "\n";
    }
};

class FunctorClassRef {
public:
    void operator()(int& i)
    {
        i *= 2;
    }
};

class FunctorClassMove {
public:
    void operator()(int&& i)
    {
        cout << i << "\n";
    }
};

class MemberClass {
public:
    void hello()
    {
        cout << "MemberClass here" << "\n";
    }
};

int main()
{
    string str = "hello world";

    std::thread threadGlobal(hello_world, std::ref(str));
    threadGlobal.join();

    cout << str << "\n";

    FunctorClass fctClass;
    std::thread threadFunctor(fctClass, 2, 5);
    threadFunctor.join();

    MemberClass memberClass;
    std::thread memberThread(&MemberClass::hello, &memberClass);
    memberThread.join();

    std::thread threadLambda([](int i, int j) {
        cout << "threadLambda here " << i + j << endl;
    },
        2, 3);
    threadLambda.join();

    FunctorClassRef fctClassRef;
    int i = 2;
    std::thread threadFunctorRef(fctClassRef, std::ref(i));
    threadFunctorRef.join();

    cout << "i " << i << "\n";

    std::thread threadLambdaRef([](int& i) {
        i *= 2;
    },
        ref(i));
    threadLambdaRef.join();
    cout << "i " << i << "\n";

    std::thread threadGlobalMove(hello_world_move, std::move(i));
    threadGlobalMove.join();
    cout << "i " << i << "\n"; // Works, but this is not guaranted!

    FunctorClassMove fctClassMove;
    int ii = 2;
    std::thread threadFunctorMove(fctClassMove, std::move(ii));
    threadFunctorMove.join();

    cout << "ii " << ii << "\n"; // Works, but this is not guaranted!

    int iii = 42;
    std::thread threadLambdaMove([](int&& i) {
        i *= 2;
    },
        std::move(iii));
    threadLambdaMove.join();
    cout << "iii " << iii << "\n"; // Works, but this is not guaranted!

    return 0;
}
