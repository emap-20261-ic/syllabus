/*
 * Jogo de adivinhar: do-while e #define.
 *
 * Sintaxe do-while:
 *   do { <corpo> } while (<condição>);
 *   O corpo é executado PELO MENOS UMA VEZ, depois a condição é verificada.
 *
 * Pontos a destacar:
 * - diferença do while: aqui faz sentido perguntar antes de checar
 * - #define target 10: macro de pré-processador (não é variável!)
 *   o pré-processador substitui o texto "target" por "10" antes de compilar
 *   convenção: nomes de macros em MAIÚSCULAS
 * - variável n para contagem de tentativas: incrementada a cada iteração
 * - testar: o que acontece se o usuário digitar 10 na primeira vez?
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
