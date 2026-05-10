#include <stdio.h>

int test(int n) {
  return n + 10;
}

int main(void) {

  int i = 1;
  // int *p = &i;

  // test(10);
  i = test(10);

  return i;
}
