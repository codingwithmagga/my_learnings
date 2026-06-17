#pragma once

#include <cstring>

template <typename T>
T mymax(T a, T b)
{
    return b < a ? a : b;
}

template <>
const char *mymax(const char *a, const char *b)
{
    return std::strcmp(b, a) < 0 ? a : b;
}

/* Alternativ:

inline const char* mymax(const char* a, const char* b)
{
    return std::strcmp(b, a) < 0 ? a : b;
}

*/