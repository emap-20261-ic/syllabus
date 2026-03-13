#include <stdio.h>

int main(void)
{
  int x, y;
  x = 0;
  y = 0;

  // prompt user 
  printf("x: ");
  scanf("%d", &x);
  
  printf("y: ");
  scanf("%d", &y);

  // perform addition
  // printf("x -> %p   y -> %p\n", &x, &y);
  printf("%i\n", x + y);
}
