#include <stdio.h>

double raiz(double x) {
  double y = 1.0;
  while ((y * y - x) > 0.001 || (y * y - x) < -0.001)
    y = (y + x / y) / 2.0;
  return y;
}

int main(void) {
  printf("square root of %f is %f\n", 16.0, raiz(16.0));
  return 0;
}
