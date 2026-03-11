/*
 * Solução para overflow: trocar int por long.
 *
 * Pontos a destacar:
 * - long tem 64 bits → comporta até 2^63 ≈ 9.2 × 10^18
 * - testar com x=2000000000 e y=2000000000: agora funciona corretamente
 * - especificador %li para long (não %d nem %i)
 * - scanf também usa %li para long
 * - lição: escolher o tipo adequado ao problema; int nem sempre é suficiente
 */
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
