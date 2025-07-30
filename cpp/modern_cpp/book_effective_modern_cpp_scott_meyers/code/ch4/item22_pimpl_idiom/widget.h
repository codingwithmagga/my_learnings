#ifndef WIDGET_H
#define WIDGET_H

#include <memory>

class Widget {
public:
    Widget();
    ~Widget();

    Widget(const Widget& rhs);
    Widget& operator=(const Widget& rhs);

    Widget(Widget&& rhs);
    Widget& operator=(Widget&& rhs);

private:
    struct Impl;
    std::unique_ptr<Impl> pImpl;
};

#endif // WIDGET_H
