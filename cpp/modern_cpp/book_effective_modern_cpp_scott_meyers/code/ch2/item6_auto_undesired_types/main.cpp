#include <iostream>
#include <vector>

class Widget {
};

std::vector<bool> features(const Widget& /* w */)
{
    std::vector<bool> features(10, true);

    return features;
}

void processWidget(const Widget& /* w */, const bool highPriority)
{
    std::cout << std::boolalpha << "Widget has high priority: " << highPriority << std::endl;
}

int main()
{
    Widget w;

    // Caution: using auto alone leads to undefined behauvior
    // auto highPriority = features(w)[5];
    bool highPriority = features(w)[5];
    auto highPriorityAuto = static_cast<bool>(features(w)[5]);

    processWidget(w, highPriority);
    processWidget(w, highPriorityAuto);

    return 0;
}
