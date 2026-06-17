#include <string>
#include <iostream>
#include <vector>

template <typename T>
class Stack
{
private:
    std::vector<T> _elements;

public:
    Stack() = default;
    Stack(std::initializer_list<T> vals) : _elements(vals) {}

    void push(const T &val)
    {
        _elements.push_back(val);
    }

    void pop()
    {
        if (empty())
        {
            throw std::out_of_range("Stack::top: empty stack");
        }
        _elements.pop_back();
    }

    const T &top() const
    {
        if (empty())
        {
            throw std::out_of_range("Stack::top: empty stack");
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
    intStack.push(2);
    intStack.push(5);
    intStack.push(12);

    std::cout << "intStack top element: " << intStack.top() << "\n";
    intStack.pop();
    std::cout << "intStack top element after removing one: " << intStack.top() << "\n";

    Stack<double> doubleStack;
    doubleStack.push(2.3);
    doubleStack.push(5.7);
    doubleStack.push(12.3);

    std::cout << "doubleStack top element: " << doubleStack.top() << "\n";
    doubleStack.pop();
    std::cout << "doubleStack top element after removing one: " << doubleStack.top() << "\n";

    Stack<std::string> stringStack;
    stringStack.push("Hello");
    stringStack.push("Template");
    stringStack.push("World");

    std::cout << "stringStack top element: " << stringStack.top() << "\n";
    stringStack.pop();
    std::cout << "stringStack top element after removing one: " << stringStack.top() << "\n";
}

/*
    Questions :

    1. Why can the same `Stack<T>` implementation be used for different types?
        Because the template parameter T will be deduced to the specified type and then work
        like a "normal" class.

    2. What requirements does `Stack<T>` impose on the type `T`?
        Copyable, moveable, destructable, printable (only for test code)

    3. Are there types for which your stack could be problematic?
        Yes. Types that are non-copyable or move-only (like std::unique_ptr) can be problematic
        because push(const T&) requires copying. Supporting such types requires move
        semantics or perfect forwarding.
*/