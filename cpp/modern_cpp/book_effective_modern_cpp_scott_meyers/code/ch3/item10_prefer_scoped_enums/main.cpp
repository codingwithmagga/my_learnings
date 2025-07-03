#include <iostream>
#include <string>
#include <tuple>

using UserInfo = std::tuple<std::string, std::string, std::size_t>;

enum class Status : std::uint32_t;
enum Color : std::uint8_t;
enum UserInfoFields { uiName,
    uiEmail,
    uiReputation };
enum class UserInfoFieldsClass { uiName,
    uiEmail,
    uiReputation };

template <typename E>
constexpr auto toUType(E enumerator) noexcept
{
    return static_cast<std::underlying_type_t<E>>(enumerator);
}

class Widget {

public:
    auto getName() const
    {
        return std::get<toUType(UserInfoFieldsClass::uiName)>(m_uInfo);
    }

    auto getEmail() const
    {
        return std::get<uiEmail>(m_uInfo);
    }

    void setStatus(Status status)
    {
        m_status = status;
    }

    void setColor(Color color)
    {
        m_color = color;
    }

private:
    Status m_status;
    Color m_color;
    UserInfo m_uInfo { "John", "info@mail.com", 2 };
};

enum class Status : std::uint32_t {
    good = 0,
    failed = 1,
    incomplete = 100,
    corrupt = 200,
    audited = 500,
    indeterminate = 0xFFFFFFFF
};

enum Color : std::uint8_t {
    white,
    red,
    blue
};

int main()
{

    // Compiler error
    enum TestColor { white,
        yellow,
        green };
    // auto white = false;

    Widget widget;
    widget.setStatus(Status::good);
    widget.setColor(red);

    std::cout << "Name: " << widget.getName() << std::endl;
    std::cout << "Email: " << widget.getEmail() << std::endl;

    return 0;
}
