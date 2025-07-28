#include <iostream>
#include <unordered_map>

class Widget { };

std::unique_ptr<const Widget> loadWidget(int id)
{
    std::cout << __FUNCTION__ << " with id " << id << " called\n";
    return std::make_unique<Widget>();
}

std::shared_ptr<const Widget> fastLoadWidget(int id)
{
    static std::unordered_map<int, std::weak_ptr<const Widget>> cache;
    auto objPtr = cache[id].lock();

    if (!objPtr) {
        std::cout << "Widget with id " << id << " not in cache\n";
        objPtr = loadWidget(id);
        cache[id] = objPtr;
    } else {
        std::cout << "Widget with id " << id << " found in cache\n";
    }
    return objPtr;
}

int main()
{
    auto spw = std::make_shared<Widget>();
    std::weak_ptr<Widget> wpw(spw);

    auto spw1 = wpw.lock();
    std::cout << std::boolalpha << "Is wpw expired? " << wpw.expired() << "\n";
    std::cout << std::boolalpha << "Is spw1 null? " << (spw1.get() == nullptr) << "\n";

    spw1 = nullptr;
    spw = nullptr;

    std::cout << std::boolalpha << "Is wpw expired? " << wpw.expired() << "\n";
    std::cout << std::boolalpha << "Is spw1 null? " << (spw1.get() == nullptr) << "\n\n";

    auto flw1 = fastLoadWidget(1);
    auto flw2 = fastLoadWidget(2);
    auto flw3 = fastLoadWidget(1);
    auto flw4 = fastLoadWidget(2);
}
