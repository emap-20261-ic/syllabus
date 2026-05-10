#include <stdio.h>

int main(void)
{
    float amount;
    printf("Dollar amount: "); scanf("%f", &amount);

    int cents = amount * 100;
    printf("Cents: %i\n", cents);
}
