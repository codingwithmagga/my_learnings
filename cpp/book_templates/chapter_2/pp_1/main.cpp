#include <string>
#include <iostream>
#include <vector>

template <typename T>
class Stack
{
private:
    std::vector<T> _elements;

public:
    Stack() {}
    Stack(std::initializer_list<T> vals) : _elements(vals) {}

    void push(const T &val)
    {
        _elements.push_back(val);
    }

    void pop()
    {
        if (!empty())
        {
            _elements.pop_back();
        }
    }

    T top() const
    {
        if (empty())
        {
            return {};
        }
        return _elements.back();
    }

    bool empty() const
    {
        return _elements.empty();
    }

    size_t size() const { return _elements.size(); }
};

int main()
{
    Stack<int> intStack;
    intStack.push(5);
    intStack.push(3);

    std::cout << std::boolalpha << "IntStack Empty: " << intStack.empty() << std::endl;
    std::cout << "IntStack size: " << intStack.size() << std::endl;
    std::cout << "IntStack top: " << intStack.top() << std::endl;

    intStack.pop();

    std::cout << std::boolalpha << "IntStack Empty: " << intStack.empty() << std::endl;
    std::cout << "IntStack size: " << intStack.size() << std::endl;
    std::cout << "IntStack top: " << intStack.top() << std::endl;

    intStack.pop();

    std::cout << std::boolalpha << "IntStack Empty: " << intStack.empty() << std::endl;
    std::cout << "IntStack size: " << intStack.size() << std::endl;

    // Check empty stack pop
    intStack.pop();

    Stack<std::string> strStack{"Hi"};
    std::cout << std::boolalpha << "strStack Empty: " << strStack.empty() << std::endl;
    std::cout << "strStack size: " << strStack.size() << std::endl;
    std::cout << "strStack top: " << strStack.top() << std::endl;
    strStack.pop();

    std::cout << std::boolalpha << "strStack Empty: " << strStack.empty() << std::endl;
    std::cout << "strStack size: " << strStack.size() << std::endl;

    // test top on empty
    std::cout << "strStack top: " << strStack.top() << std::endl;
}

/*
    Questions :

    1. Why is `Stack<T>` a **class template** and not a normal class?
        Similar to container classes from the std library Stack can hold arbitrary types.
        TO make this work it needs to be a class template.

    2. Which member functions should be `const`?
        empty() and size() should definetly be const
        top() can be const too if the value is just returned and not popped
        and the return value is a copy and not a reference as choosen here

    3. What should happen if `pop()` or `top()` is called on an empty stack?
        For pop() it is relatively simple, nothing happens
        top() needs to return a T (or T&).
        I choosed to return a default value.
        Other option could be to raise an exception.
        Or use std::optional<T> as return type returning a std::nullopt if stack is empty.

*/