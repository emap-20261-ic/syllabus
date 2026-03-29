/*
 * Integer division and floating-point imprecision.
 *
 * Key points:
 * - int / int = int (truncated): division happens BEFORE conversion to float
 *   float z = 2 / 3 → z = 0.0 (not 0.666...)
 * - fix: explicit cast before division:
 *   float z = (float) x / (float) y;
 *   one float operand is enough to make the division floating-point
 * - test with x=2, y=3 → output shows floating-point imprecision:
 *   0.66666668... (not 0.66666666...)
 * - this is not a bug: it is the IEEE 754 limitation (finite binary representation)
 * - the commented line shows the fix with cast
 */
// division with integers, demonstrating truncation
#include <stdio.h>

int main(void)
{
  int x, y;

  printf("x: "); scanf("%d", &x);
  printf("y: "); scanf("%d", &y);

  float z = (int) x / (float) y;
  printf("%f\n", z);
}
