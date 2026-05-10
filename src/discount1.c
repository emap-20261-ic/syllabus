#include <stdio.h>

float discount(float price);

int main(void)
{
    float regular;
    printf("regular price: "); scanf("%f", &regular);

    float sale = discount(regular);
    printf("sale Price: %.2f\n", sale);
}

float discount(float price)
{
    return price * .85;
}
