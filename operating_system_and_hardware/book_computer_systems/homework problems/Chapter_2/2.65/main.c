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

/* Return 1 when x contains an odd number of 1s; 0 otherwise. Assume w=32 */
int odd_ones(unsigned x)
{

    x ^= (x >> 16);
    x ^= (x >> 8);
    x ^= (x >> 4);
    x ^= (x >> 2);
    x ^= (x >> 1);

    return x & 0x01;
}

int main()
{
    unsigned xlow = 1;
    unsigned xmid = 0x67665599;
    unsigned xhigh = 0xFFAABBCC;
    unsigned zero = 0x00000000;
    unsigned ones = 0x11111111;

    printf("%i \n", odd_ones(xlow));
    printf("%i \n", odd_ones(xmid));
    printf("%i \n", odd_ones(xhigh));
    printf("%i \n", odd_ones(zero));
    printf("%i \n", odd_ones(ones));

    return 0;
}