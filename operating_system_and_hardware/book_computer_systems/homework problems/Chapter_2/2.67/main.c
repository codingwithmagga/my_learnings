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

void show_unsigned_bits(unsigned x)
{
    show_bits((byte_pointer)&x, sizeof(unsigned));
}

/* The following code does not run properly on some machines */
int bad_int_size_is_32()
{
    /* Set most significant bit (msb) of 32-bit machine */
    int set_msb = 1 << 31;
    /* Shift past msb of 32-bit word */
    int beyond_msb = 1 << 32;
    /* set_msb is nonzero when word size >= 32
    beyond_msb is zero when word size <= 32 */
    return set_msb && !beyond_msb;
}

int int_size_is_32()
{

    unsigned set_msb = 1u << 15; /* sicher bei int >= 16 */
    set_msb = set_msb << 15;     /* jetzt Bit 30 */
    set_msb = set_msb << 1;      /* jetzt Bit 31 */

    unsigned beyond_msb = set_msb << 1;
    return set_msb && !beyond_msb;
}

// A: Shifting greater than width type

int main()
{

    printf("%i \n", int_size_is_32());

    return 0;
}