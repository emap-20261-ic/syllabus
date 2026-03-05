// addition with long
#include <stdio.h>

int main(void) { 
  long x, y;

  /* https://www.programiz.com/c-programming/c-input-output
     http://personal.ee.surrey.ac.uk/Personal/R.Bowden/C/scanf.html */
  printf("x: "); scanf("%li", &x);
  printf("y: "); scanf("%li", &y);

  // perform addition
  printf("%li\n", x + y);
}
