/*
 * Floating-point imprecision: the cents problem.
 *
 * Key points:
 * - ask before testing: what will be printed for 4.20?
 * - test: 0.99 → 99 ✓, 1.23 → 123 ✓, 4.20 → 419 ✗ (expected: 420)
 * - cause: 4.20 cannot be represented exactly in binary
 *   stored internally as 4.19999980...
 *   4.19999980 * 100 = 419.99998... → truncated to int → 419
 * - NOT a C bug; it is a fundamental limitation of floating-point (IEEE 754)
 * - fix: use round() before converting to int (see cents1.c)
 */
#include <stdio.h>

int main(void)
{
    float amount;
    printf("Dollar amount: "); scanf("%f", &amount);

    int cents = amount * 100;
    printf("Cents: %i\n", cents);
}
