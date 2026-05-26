#include <stdio.h>
#include <stdbool.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len)
{
    int i;
    for (i = 0; i < len; i++)
        printf(" %.2x", start[i]);
    printf("\n");
}

void show_int(int x)
{
    show_bytes((byte_pointer)&x, sizeof(int));
}

int combine(int x, int y)
{
    return (x & 0xFF) | (y & ~0xFF);
}

int main()
{
    int x = 2000;
    int y = 100222200;

    int s = combine(x, y);

    printf("Combined value: %d\n", s);

    printf("\nBytes of x: ");
    show_int(x);

    printf("Bytes of y: ");
    show_int(y);

    printf("Bytes of s: ");
    show_int(s);

    return 0;
}