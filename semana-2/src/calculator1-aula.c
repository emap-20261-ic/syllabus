/*
 * Primeiro exemplo com printf e scanf juntos.
 *
 * Pontos a destacar:
 * - scanf recebe o ENDEREÇO da variável: &x e &y (operador &)
 * - sem o &, scanf não sabe onde escrever na memória (erro silencioso)
 * - %i é equivalente a %d para int
 * - padrão: printf para prompt, scanf para leitura, na mesma linha
 */
#include <stdio.h>

int main(void)
{
  int x, y;

  // prompt user
  printf("x: "); scanf("%d", &x);
  printf("y: "); scanf("%d", &y);

  // perform addition
  printf("%i\n", x + y);
}
