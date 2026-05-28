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
/* Return 1 when any odd bit of x equals 1; 0 otherwise. Assume w=32 */
int any_odd_one(unsigned x)
{
    show_unsigned_bits(x);
    unsigned mask = 0xAAAAAAAA;
    show_unsigned_bits(mask);
    x &= mask;

    show_unsigned_bits(x);

    return !!x;
}

int main()
{
    unsigned xlow = 1;
    unsigned xmid = 0x67665599;
    unsigned xhigh = 0xFFAABBCC;
    unsigned zero = 0x00000000;
    unsigned ones = 0x11111111;

    printf("%i \n", any_odd_one(xlow));
    printf("%i \n", any_odd_one(xmid));
    printf("%i \n", any_odd_one(xhigh));
    printf("%i \n", any_odd_one(zero));
    printf("%i \n", any_odd_one(ones));

    return 0;
}