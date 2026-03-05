#include <stdio.h>

int main(void)
{
    float regular;
    printf("regular price: "); scanf("%f", &regular);
    
    float sale = regular * .85;
    printf("Sale Price: %.2f\n", sale);
}
