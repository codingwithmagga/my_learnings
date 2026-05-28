#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer bytes, int len)
{
    for (int i = 0; i < len; ++i)
    {
        printf(" %.2x", bytes[i]);
    }
    printf("\n");
}

void show_int(int x)
{
    show_bytes((byte_pointer)&x, sizeof(int));
}

unsigned srl(unsigned x, int k)
{
    show_int(x);
    /* Perform shift arithmetically */
    unsigned xsra = (int)x >> k;

    show_int(xsra);

    xsra = xsra & (-1u >> k);

    show_int(xsra);

    return xsra;
}

int sra(int x, int k)
{
    show_int(x);

    /* Perform shift logically */
    int xsrl = (unsigned)x >> k;
    int w = sizeof(int) * 8;

    show_int(xsrl);

    int sign = x >> (w - 1);
    int mask = sign << (w - k);
    xsrl = xsrl | mask;
    show_int(xsrl);

    return xsrl;
}

int main()
{

    unsigned xlow = 1;
    unsigned xmid = 0x67665599;
    unsigned xhigh = 0xFFAABBCC;

    int k = 6;

    srl(xlow, k);
    printf("Sol.:");
    show_int(xlow >> k);

    printf("\n");

    srl(xmid, k);
    printf("Sol.:");
    show_int(xmid >> k);

    printf("\n");

    srl(xhigh, k);
    printf("Sol.:");
    show_int(xhigh >> k);

    int xneg = -1;
    int xlowi = 1;
    int xmidi = 0x67665599;
    int xhighi = 0xFFAABBCC;
    printf("\n\n sra: \n");

    sra(xneg, k);
    printf("Sol.:");
    show_int(xneg >> k);

    printf("\n");

    sra(xlowi, k);
    printf("Sol.:");
    show_int(xlowi >> k);

    printf("\n");

    sra(xmidi, k);
    printf("Sol.:");
    show_int(xmidi >> k);

    printf("\n");

    sra(xhighi, k);
    printf("Sol. to xhigh: %i \n", xhighi);
    show_int(xhighi >> k);

    return 0;
}