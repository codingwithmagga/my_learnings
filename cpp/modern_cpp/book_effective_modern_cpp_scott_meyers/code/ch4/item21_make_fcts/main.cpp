#include <iostream>
#include <vector>

class Widget { };

int computePriority()
{
    return 1;
}

void processWidget(std::shared_ptr<Widget> spw, int priority)
{
    std::cout << __FUNCTION__ << " called\n";
}

void cusDel(Widget* ptr)
{
    std::cout << __FUNCTION__ << " called\n";
    delete ptr;
}

int main()
{
    processWidget(std::make_shared<Widget>(), computePriority());
    std::shared_ptr<Widget> spw(new Widget, cusDel);
    processWidget(std::move(spw), computePriority());

    auto upvParentheses = std::make_unique<std::vector<int>>(10, 20);
    auto initList = { 10, 20 };
    auto upvInitList = std::make_unique<std::vector<int>>(initList);

    std::cout << "upvParentheses is a vector with " << upvParentheses->size() << " elements\n";
    std::cout << "upvInitList is a vector with     " << upvInitList->size() << " elements\n";
}
