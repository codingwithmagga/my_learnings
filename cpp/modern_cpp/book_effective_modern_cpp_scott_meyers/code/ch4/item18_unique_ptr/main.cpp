#include <iostream>
#include <memory>

class Investment {
public:
    virtual ~Investment() { }
};

class Stock : public Investment {
public:
    Stock()
    {
        std::cout << "Stock class created\n";
    }
};

class Bond : public Investment {
public:
    Bond()
    {
        std::cout << "Bond class created\n";
    }
};

class RealEstate : public Investment {
public:
    RealEstate()
    {
        std::cout << "RealEstate class created\n";
    }
};

enum class InvestmentType { Stock,
    Bond,
    RealEstate };

template <typename... Ts>
auto makeInvestment(InvestmentType type, Ts&&... params)
{
    auto delInvmt = [](Investment* pInvestment) {
        std::cout << "Delete Investment\n";
        delete pInvestment;
    };

    std::unique_ptr<Investment, decltype(delInvmt)>
        pInv(nullptr, delInvmt);

    if (type == InvestmentType::Stock) {
        pInv.reset(new Stock(std::forward<Ts>(params)...));
    } else if (type == InvestmentType::Bond) {
        pInv.reset(new Bond(std::forward<Ts>(params)...));
    } else if (type == InvestmentType::RealEstate) {
        pInv.reset(new RealEstate(std::forward<Ts>(params)...));
    }

    return pInv;
}

int main()
{
    auto investment1 = makeInvestment(InvestmentType::Stock);
    auto investment2 = makeInvestment(InvestmentType::Bond);
    auto investment3 = makeInvestment(InvestmentType::RealEstate);
}
