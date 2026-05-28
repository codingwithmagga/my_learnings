#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

int int_shifts_are_arithmetic()
{
    int x = -1;
    int y = x >> 1;

    return x == y;
}

int main()
{
    printf("Right arithemtic shifts? %d", int_shifts_are_arithmetic());
    printf("\n");

    return 0;
}