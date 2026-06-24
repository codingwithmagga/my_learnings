#include <string>
#include <iostream>
#include <deque>
#include <vector>

template <typename T, typename Cont = std::vector<T>>
class Stack
{

    using value_type = T;
    using container_type = Cont;
    using size_type = typename Cont::size_type;

public:
    Stack() = default;
    Stack(std::initializer_list<value_type> vals) : _elements(vals) {}

    void push(const T &val)
    {
        _elements.push_back(val);
    }

    void pop()
    {
        if (empty())
        {
            throw std::out_of_range("Stack::pop: empty stack");
        }
        _elements.pop_back();
    }

    const value_type &top() const
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

    size_type size() const { return _elements.size(); }

    void print() const
    {
        std::cout << "Stack contains the following elements:" << '\n';
        for (auto it = std::crbegin(_elements); it != std::crend(_elements); it++)
        {
            std::cout << *it << '\n';
        }
    }

private:
    container_type _elements;
};

int main()
{
    Stack<int> a;
    Stack<std::string> b;
    Stack<int, std::deque<int>> c;

    a.push(2);
    a.push(5);
    a.push(12);
    a.print();

    std::cout << "a top element: " << a.top() << "\n";
    a.pop();
    std::cout << "a top element after removing one: " << a.top() << "\n";
    std::cout << "\n";

    b.push("Hello");
    b.push("Template");
    b.push("World");
    b.print();

    std::cout << "b top element: " << b.top() << "\n";
    b.pop();
    std::cout << "b top element after removing one: " << b.top() << "\n";
    std::cout << "\n";

    c.push(5);
    c.push(1);
    c.push(2);
    c.print();

    std::cout << "c top element: " << c.top() << "\n";
    c.pop();
    std::cout << "c top element after removing one: " << c.top() << "\n";
}

/*
    Questions:

    1. What are the advantages of the second template parameter `Cont`?
        The user can choose the underlying container which stores the elements.

    2. Why is `std::vector<T>` a sensible default?
        In many general cases `std::vector<T>` is a viable choice.

    3. What does “partial usage” mean concretely in:
        ```cpp
        Stack<int>
        ```
            It means that only the first template is specified by the user. For the second template parameter Cont
            the default type is used.

    4. What requirements must `Cont` satisfy so that your stack works?
        Necessary functions: push_back, pop_back, back, empty, size
        Provide const reverse iterators
        Accepting a std::initializer_lists<T> in the ctor.

*/