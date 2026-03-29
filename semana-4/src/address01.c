#include <stdio.h>

int main(void) {
  
  int n = 50;
  int *p = &n;
  
  printf("at %p the value is %d\n", p, *p);
  printf("at %p the value is %d\n", &n, n);
}
