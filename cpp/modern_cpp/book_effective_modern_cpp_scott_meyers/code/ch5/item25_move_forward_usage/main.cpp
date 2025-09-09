#include <iostream>
#include <string>

class String : public std::string {

public:
    String()
        : std::string()
    {
        std::cout << "Default ctor called" << std::endl;
    };

    String(const char* text)
        : std::string(text)
    {
        std::cout << "String ctor (char*) called" << std::endl;
    }

    String(const std::string& data)
        : std::string(data)
    {
        std::cout << "String ctor (string) called" << std::endl;
    }

    String(const String& rhs)
        : std::string(rhs)
    {
        std::cout << "Copy ctor called" << std::endl;
    }

    String& operator=(const String& rhs)
    {
        std::cout << "Copy assignment called" << std::endl;
        std::string::operator=(rhs); // assign base part
        return *this;
    }

    String(String&& rhs)
        : std::string(rhs)
    {
        std::cout << "Move ctor called" << std::endl;
    }

    String& operator=(String&& rhs) noexcept
    {
        std::cout << "Move assignment called\n";
        std::string::operator=(std::move(rhs));
        return *this;
    }
};

class Widget1 {
public:
    template <typename T>
    void setName(T&& newName)
    {
        name = std::move(newName);
    }

private:
    String name;
};

class Widget2 {
public:
    void setName(const String& newName)
    {
        name = newName;
    }
    void setName(String&& newName)
    {
        name = std::move(newName);
    }

private:
    String name;
};

String createName()
{
    return String("Created Name");
}

int main()
{
    Widget1 w1;
    Widget2 w2;

    // For MSVC and GNU++ (debug and release) there is no difference between both calls.
    // Not sure if my addition of String is the issue or the compiler already optimizes this away.
    // KI (ChatGPT, DeepSeek) couldn't really help either.

    std::cout << "\n--- Universal reference with function return ---\n";
    w1.setName(createName());

    std::cout << "\n--- Overloaded with function return ---\n";
    w2.setName(createName());
}
