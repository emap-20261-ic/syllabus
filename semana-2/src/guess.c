#include <stdio.h>

#define target 10

int main() {
  int r, n = 0;
  
  do {
    printf("n: "); scanf("%d", &r);
    if (r != target)
      printf("%d is wrong, again!\n", r);
    n++;
  } while (r != target);
  
  printf("%d is right, you made %d attempt(s).\n", r, n);
  return 0;
}
