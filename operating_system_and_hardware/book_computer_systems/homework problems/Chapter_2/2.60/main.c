#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len)
{
    int i;
    for (i = 0; i < len; i++)
        printf(" %.2x", start[i]);
    printf("\n");
}

void show_int(int32_t x)
{
    show_bytes((byte_pointer)&x, sizeof(int32_t));
}

unsigned replace_byte(unsigned x, int i, unsigned char b)
{
    unsigned mask = 0xFF;
    mask <<= (i << 3);

    unsigned bb = b;
    bb <<= (i << 3);

    return (x & ~mask) | bb;
}

int main()
{

    int32_t x = 99999977;

    for (int32_t i = 0; i < sizeof(int32_t); ++i)
    {
        int32_t s = replace_byte(x, i, 0x77);

        printf("\nByte number: %d\n", i);
        printf("Bytes of x: ");
        show_int(x);

        printf("replaced byte: ");
        show_int(s);
    }

    return 0;
}