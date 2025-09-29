#include <iostream>
#include <string>

class LifecycleLogger
{
public:
    LifecycleLogger(const std::string &name = "LifecycleLogger")
        : m_name(name)
    {
        std::cout << m_name << " - Default ctor called\n";
    }

    ~LifecycleLogger() { std::cout << m_name << " - Destructor called\n"; }

    LifecycleLogger(const LifecycleLogger &rhs)
        : m_name(rhs.m_name)
    {
        std::cout << m_name << " - Copy ctor called\n";
    }

    LifecycleLogger &operator=(const LifecycleLogger &rhs)
    {
        std::cout << m_name << " - Copy assignment called\n";
        return *this;
    }

    LifecycleLogger(LifecycleLogger &&rhs) noexcept
        : m_name(rhs.m_name)
    {
        std::cout << m_name << " - Move ctor called\n";
    }

    LifecycleLogger &operator=(LifecycleLogger &&rhs) noexcept
    {
        std::cout << m_name << " - Move assignment called\n";
        return *this;
    }

private:
    std::string m_name;
};
