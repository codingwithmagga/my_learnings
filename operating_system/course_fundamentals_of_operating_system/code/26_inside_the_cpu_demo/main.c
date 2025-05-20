#include <stdio.h>

int main()
{
    long long sum = 0;
    int i;

    for(i=1; i<=900000000; ++i) {
        sum +=i;
    }

    printf("Sum: %lld\n", sum);

    return 0;
}
