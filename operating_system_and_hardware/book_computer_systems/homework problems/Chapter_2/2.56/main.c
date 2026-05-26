#include "stdio.h"

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

void show_float(float x)
{
    show_bytes((byte_pointer)&x, sizeof(float));
}

void show_pointer(void *x)
{
    show_bytes((byte_pointer)&x, sizeof(void *));
}

void test_show_bytes(int val)
{
    int ival = val;
    float fval = (float)ival;
    int *pval = &ival;

    show_int(val);
    show_float((float)val);
    show_pointer(pval);
}

int main()
{
    printf("Testing with various integer values:\n\n");

    printf("Testing with 12345:\n");
    test_show_bytes(12345);
    printf("\nTesting with 0:\n");
    test_show_bytes(0);
    printf("\nTesting with -12345:\n");
    test_show_bytes(-12345);
    printf("\nTesting with -2147483648:\n");
    test_show_bytes(-2147483648);
    printf("\nTesting with 2147483647:\n");
    test_show_bytes(2147483647);

    // under–/overflow

    printf("\nTesting with -2147483649:\n");
    test_show_bytes((int)-2147483649);
    printf("\nTesting with 2147483648:\n");
    test_show_bytes((int)2147483648);

    return 0;
}