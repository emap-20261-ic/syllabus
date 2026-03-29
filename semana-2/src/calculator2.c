#include <stdio.h>

int main(void)
{
    float x, y;

    printf("x: "); scanf("%f", &x);
    printf("y: "); scanf("%f", &y);

    float z = x / y;
    // double z = (double) x / (double) y;
    printf("%.20f\n", z);
}
