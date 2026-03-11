/*
 * Paridade: uso do operador módulo (%) e if/else simples.
 *
 * Pontos a destacar:
 * - operador %: resto da divisão inteira. Ex: 7 % 2 = 1, 4 % 2 = 0
 * - n % 2 == 0 → n é par; n % 2 != 0 → n é ímpar
 * - cuidado com negativos: -3 % 2 em C pode ser -1 (depende da implementação em C89,
 *   definido como truncamento em C99+)
 * - if/else sem chaves: ok para uma única instrução, mas use chaves por hábito
 */
#include <stdio.h>

int main(void)
{
  int n;
  printf("n: ");
  scanf("%d", &n);

  if (n % 2 == 0)
    printf("even\n");
  else
    printf("odd\n");
}
