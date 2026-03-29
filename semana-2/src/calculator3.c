// truncation
#include <stdio.h>

int main(void)
{
    long x, y;

    printf("x: "); scanf("%li", &x);
    printf("y: "); scanf("%li", &y);

    // divide x by y
    float z = x / y;
    printf("%f\n", z);
}
