#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

typedef unsigned char *byte_pointer;

void show_bits(byte_pointer bytes, size_t len)
{
    for (size_t i = 0; i < len; ++i)
    {
        unsigned char byte = bytes[i];
        for (int b = 7; b >= 0; --b)
        {
            printf("%c", (byte & (1 << b)) ? '1' : '0');
        }
        printf(" ");
    }
    printf("\n");
}

void show_bytes(byte_pointer bytes, size_t len)
{
    for (int i = 0; i < len; ++i)
    {
        printf(" %.2x", bytes[i]);
    }
    printf("\n");
}

void show_int_bits(int x)
{
    show_bits((byte_pointer)&x, sizeof(int));
}

void show_unsigned_bits(int x)
{
    show_bits((byte_pointer)&x, sizeof(unsigned));
}

/* * : Generate mask indicating leftmost 1 in x. Assume w=32. *
 *  For example, OxFFOO —-> 0x8000, and 0x6600 --> 0x4000. *
 * If x = 0, then return 0. */
int leftmost_one(unsigned x)
{
}

int main()
{
    unsigned xlow = 1;
    unsigned xmid = 0x67665599;
    unsigned xhigh = 0xFFAABBCC;
    unsigned zero = 0x00000000;
    unsigned ones = 0x11111111;

    printf("%i \n", leftmost_one(xlow));
    printf("%i \n", leftmost_one(xmid));
    printf("%i \n", leftmost_one(xhigh));
    printf("%i \n", leftmost_one(zero));
    printf("%i \n", leftmost_one(ones));

    return 0;
}