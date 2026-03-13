#include <stdio.h>

int main(void) {
  int n = -1;
  printf("n (positivo): ");
  scanf("%d", &n);

  if(n < 0)
    return 1;

  if (n % 2 == 0)
    printf("even\n");
  else
    printf("odd\n");
  return 0;
}
