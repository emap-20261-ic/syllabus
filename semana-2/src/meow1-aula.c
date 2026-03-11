/*
 * Repetição com while.
 *
 * Sintaxe: while (<condição>) <corpo>
 * O corpo é executado enquanto a condição for verdadeira.
 *
 * Pontos a destacar:
 * - i começa em 0 (convenção em C: índices começam em 0)
 * - i++ é incremento pós-fixo: equivalente a i = i + 1
 *   (também existe i++: pré-fixo; a diferença importa em expressões)
 * - condição i++ < 3: avalia i (0, 1, 2), depois incrementa
 *   → loop executa 3 vezes (quando i==3, condição é falsa, para)
 * - comparar com meow0.c: qualquer número de repetições, uma linha a mudar
 */
#include <stdio.h>

int main(void) {

  int i = 0;
  while( i++ < 3 )
    printf("meow\n");
}
