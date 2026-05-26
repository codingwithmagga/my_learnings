#include <stdio.h>
#include <stdbool.h>

typedef unsigned char *byte_pointer;

bool is_little_endian()
{
    int x = 1;
    return ((byte_pointer)&x)[0] == 1;
}

int main()
{
    printf("Is little-endian? %s\n", is_little_endian() ? "Yes" : "No");
    return 0;
}