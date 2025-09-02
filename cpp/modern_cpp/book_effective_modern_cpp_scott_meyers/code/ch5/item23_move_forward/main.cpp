#include <chrono>
#include <iostream>

class String : public std::string {

public:
    String(const std::string& data)
        : std::string(data)
    {
        std::cout << "String ctor called" << std::endl;
    }

    String(const String& rhs)
        : std::string(rhs)
    {
        std::cout << "Copy ctor called" << std::endl;
    }
    String(String&& rhs)
        : std::string(rhs)
    {
        std::cout << "Move ctor called" << std::endl;
    }
};

class Annotation {
public:
    explicit Annotation(const String& text)
        : value(std::move(text))
    {
    }

    explicit Annotation(String&& text)
        : value(std::move(text))
    {
    }

private:
    String value;
};

class Widget { };

void process(const Widget& lvalArg)
{
    std::cout << "Process with lvalue called." << std::endl;
}
void process(Widget&& rvalArg)
{
    std::cout << "Process with rvalue called." << std::endl;
}

template <typename T>
void logAndProcess(T&& param)
{
    auto now = std::chrono::system_clock::now();
    std::cout << "Make log entry: " << now.time_since_epoch().count() << std::endl;
    process(std::forward<T>(param));
}

int main()
{
    String str { "annotation_text" };
    Annotation annotation(std::move(str));

    Widget w;
    logAndProcess(w);
    logAndProcess(std::move(w));
}
