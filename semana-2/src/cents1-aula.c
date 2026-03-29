/*
 * Fix for float imprecision: the round() function.
 *
 * Key points:
 * - #include <math.h> and flag -lm to compile
 * - round(x): rounds to the nearest integer (returns double)
 * - round(4.19999... * 100) = round(419.9999...) = 420.0 → int: 420
 * - test with the same values as cents0.c: now 4.20 → 420 ✓
 * - round() vs truncation: without round, 419.999 → 419; with round → 420
 * - lesson: when working with monetary values, beware of float;
 *   robust alternative: always work in cents (integers)
 */
#include <math.h>
#include <stdio.h>

int main(void)
{
    float amount;
    printf("Dollar amount: ");
    scanf("%f", &amount);

    int cents = round(amount * 100);
    printf("Cents: %i\n", cents);
}
