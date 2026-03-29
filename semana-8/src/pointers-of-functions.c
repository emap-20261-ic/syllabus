#include <stdio.h>


int add(int a, int b) {
    return a + b;
}

int main(void) {


  int x = 10;
  int *y = &x;
  
  int (*test)(int, int) = add;
  int sum = (*test)(5, 3);
  printf("Sum: %d\n", sum);
  return 0;
}

