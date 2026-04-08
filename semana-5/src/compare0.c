#include <stdio.h>

int main(void) {

  int i = 12;
  int j = 45;

  // a + b ~> add(a, b)

  // test ? value-true : value-false ~>
  // COND(test, value-true, value-false)
  int r = (i == j ? 10 : 20);

  printf("r = %i\n", r);
}
