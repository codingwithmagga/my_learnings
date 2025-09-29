#include <iostream>
#include <memory>
#include <vector>

class BaseWrong {
public:
    virtual void mf1() const
    {
        std::cout << "BaseWrong::mf1() called" << std::endl;
    }
    virtual void mf2(int x)
    {
        std::cout << "BaseWrong::mf2() called" << std::endl;
    }
    virtual void mf3() &
    {
        std::cout << "BaseWrong::mf3() called" << std::endl;
    }
    void mf4() const
    {
        std::cout << "BaseWrong::mf4() called" << std::endl;
    }
};

class DerivedWrong : public BaseWrong {
public:
    virtual void mf1()
    {
        std::cout << "DerivedWrong::mf1() called" << std::endl;
    }
    virtual void mf2(unsigned int x)
    {
        std::cout << "DerivedWrong::mf2() called" << std::endl;
    }
    virtual void mf3() &&
    {
        std::cout << "DerivedWrong::mf3() called" << std::endl;
    }
    void mf4() const
    {
        std::cout << "DerivedWrong::mf4() called" << std::endl;
    }
};

class Base {
public:
    virtual void mf1() const
    {
        std::cout << "Base::mf1() called" << std::endl;
    }
    virtual void mf2(int x)
    {
        std::cout << "Base::mf2() called" << std::endl;
    }
    virtual void mf3() &
    {
        std::cout << "Base::mf3() called" << std::endl;
    }
    virtual void mf4() const
    {
        std::cout << "Base::mf4() called" << std::endl;
    }
};

class Derived : public Base {
public:
    virtual void mf1() const override
    {
        std::cout << "Derived::mf1() called" << std::endl;
    }
    virtual void mf2(int x) override
    {
        std::cout << "Derived::mf2() called" << std::endl;
    }
    virtual void mf3() & override
    {
        std::cout << "Derived::mf3() called" << std::endl;
    }
    void mf4() const override
    {
        std::cout << "Derived::mf4() called" << std::endl;
    }
};

class Widget {
public:
    using DataType = std::vector<double>;
    DataType& data() &
    {
        std::cout << "Calls lvalue overload.\n";
        return values;
    }
    DataType data() &&
    {
        std::cout << "Calls rvalue overload.\n";
        return std::move(values);
    }

private:
    DataType values;
};

Widget makeWidget()
{
    Widget widget;
    return widget;
}

int main()
{
    std::unique_ptr<BaseWrong> derivedWrong = std::make_unique<DerivedWrong>();
    std::unique_ptr<Base> derived = std::make_unique<Derived>();

    const int test = 0;

    derivedWrong->mf1();
    derivedWrong->mf2(test);
    derivedWrong->mf3();
    derivedWrong->mf4();

    std::cout << "\n";

    derived->mf1();
    derived->mf2(test);
    derived->mf3();
    derived->mf4();

    std::cout << "\n";

    Widget widget;
    auto vals1 = widget.data();
    auto vals2 = makeWidget().data();

    return 0;
}
