/*
 * Guessing game: do-while and #define.
 *
 * do-while syntax:
 *   do { <body> } while (<condition>);
 *   The body runs AT LEAST ONCE, then the condition is checked.
 *
 * Key points:
 * - difference from while: here it makes sense to ask before checking
 * - #define target 10: preprocessor macro (not a variable!)
 *   the preprocessor replaces "target" with "10" before compiling
 *   convention: macro names in UPPERCASE
 * - variable n counts attempts: incremented each iteration
 * - test: what happens if the user types 10 on the first try?
 */
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
