#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

int taskA(int32_t x)
{
    return !!x;
}

int taskB(int32_t x)
{
    return !!~x;
}

int taskC(int x)
{
    return !!(x & 0xFF);
}

int taskD(int x)
{
    return !!~(x >> 24);
}

int main()
{

    int32_t x0 = 0;
    int32_t x1 = 1;
    int32_t x2 = 0xFFFFFFFF;
    int32_t x3 = 0x89ABCDEF;

    // A
    int Ax0 = taskA(x0);
    int Ax1 = taskA(x1);
    int Ax2 = taskA(x2);

    printf("Ax0 %d\n", Ax0);
    printf("Ax1 %d\n", Ax1);
    printf("Ax2 %d\n", Ax2);

    // B
    int Bx0 = taskB(x0);
    int Bx1 = taskB(x1);
    int Bx2 = taskB(x2);

    printf("\n");
    printf("Bx0 %d\n", Bx0);
    printf("Bx1 %d\n", Bx1);
    printf("Bx2 %d\n", Bx2);

    // C
    int Cx0 = taskC(x0);
    int Cx1 = taskC(x1);
    int Cx2 = taskC(x2);

    printf("\n");
    printf("Cx0 %d\n", Cx0);
    printf("Cx1 %d\n", Cx1);
    printf("Cx2 %d\n", Cx2);

    // D
    int Dx0 = taskD(x0);
    int Dx1 = taskD(x1);
    int Dx2 = taskD(x2);
    int Dx3 = taskD(x3);

    printf("\n");
    printf("Dx0 %d\n", Dx0);
    printf("Dx1 %d\n", Dx1);
    printf("Dx2 %d\n", Dx2);
    printf("Dx3 %d\n", Dx3);

    return 0;
}