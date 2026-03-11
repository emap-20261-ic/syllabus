/*
 * Mario com for simples: 4 blocos fixos em uma linha.
 *
 * Pontos a destacar:
 * - o número 4 está "hard-coded" — e se quisermos outro tamanho?
 * - próximo passo (mario2.c): pedir o tamanho ao usuário
 * - printf("?") sem \n: mantém na mesma linha; \n só ao final
 */
#include <stdio.h>

int main(void) {
  
  for (int i = 0; i < 4; i++) {
    printf("?");
  }
  printf("\n");
}
