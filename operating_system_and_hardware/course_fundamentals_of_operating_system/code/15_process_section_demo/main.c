#include <stdio.h>
#include <stdlib.h>

int A = 1800;

int main()
{
    long long sum = 0;
    int i;
    int *nums = (int *) malloc(100000*sizeof(int));

    // Reduced the number of loop iterations
    for(i=1; i<=90000; ++i) {
        sum +=i;
    }

    printf("Sum: %lld\n", sum);

    return 0;
}
