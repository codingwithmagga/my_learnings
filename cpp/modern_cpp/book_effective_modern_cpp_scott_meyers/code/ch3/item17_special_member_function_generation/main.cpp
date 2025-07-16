#include <iostream>
#include <map>
#include <string>

class Base {
public:
    Base() = default;
    virtual ~Base() = default;

    Base(Base&&) = default;
    Base& operator=(Base&&) = default;

    Base(const Base&) = default;
    Base& operator=(const Base&) = default;
};

class StringTable : public Base {
public:
    StringTable() { makeLogEntry("Creating StringTable object"); }
    ~StringTable() { makeLogEntry("Destroying StringTable object"); }

    StringTable(const StringTable&) = default;
    StringTable(StringTable&&) = delete;
    StringTable& operator=(const StringTable&) = default;
    StringTable& operator=(StringTable&&) = delete;

private:
    void makeLogEntry(const std::string& log)
    {
        std::cout << log << "\n";
    }

    std::map<int, std::string> values;
};

int main()
{
    // I'm not really sure what to show here.
    // I can't really check if the move operations are default generated or not.
    StringTable table;
}
