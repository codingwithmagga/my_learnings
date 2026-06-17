#include <string>
#include <iostream>
#include <deque>
#include <vector>

template <typename T, typename Cont = std::vector<T>>
class Stack
{

    using value_type = T;
    using container_type = Cont;

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

    size_t size() const { return _elements.size(); }

private:
    container_type _elements;
};

int main()
{
    Stack<int> s1;
    s1.push(2);
    s1.push(5);
    s1.push(12);

    std::cout << "s1 top element: " << s1.top() << "\n";
    s1.pop();
    std::cout << "s1 top element after removing one: " << s1.top() << "\n";

    Stack<int, std::deque<int>> s2;
    s2.push(3);
    s2.push(7);
    s2.push(2);

    std::cout << "s2 top element: " << s2.top() << "\n";
    s2.pop();
    std::cout << "s2 top element after removing one: " << s2.top() << "\n";
}

/*
    Questions :

    1. What does “partial usage of class templates” mean here?
        Only specifying a part of the template parameters like in Stack<int>.

    2. Why can you omit the second template parameter in `Stack<int>`?
        Because it has a default template type.

    3. What are type aliases useful for in template classes?
        Better readability. Generic code. Change at one place. Stable APIs.

*/