// division with integers, demonstrating truncation
#include <stdio.h>

int main(void)
{
  int x, y;

  printf("x: "); scanf("%d", &x);
  printf("y: "); scanf("%d", &y);

  float z = x / y; 
  // float z = (float) x / (float) y;
  printf("%f\n", z);
}
