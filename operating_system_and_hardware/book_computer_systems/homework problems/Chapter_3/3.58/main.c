#include "stdio.h"

// %rdi, %rsi, %rdx
long decode2(long x, long y, long z)
{
    long t = y - z;
    long mask = (t << 63) >> 63;
    return (x * t) ^ mask;
}

int main()
{
    return 0;
}