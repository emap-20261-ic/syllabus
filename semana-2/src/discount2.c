#include <stdio.h>

float discount(float price, int percent);

int main(void)
{
  float regular;
  printf("regular price: "); scanf("%f", &regular);
  
  int percent_off;
  printf("  percent off: "); scanf("%d", &percent_off);
  
  float sale = discount(regular, percent_off);
  printf("   sale price: %.2f\n", sale);
}

float discount(float price, int t)
{
  return price * (100 - t) / 100;
}
