/*
 * Repetição com for.
 *
 * Sintaxe: for (<init>; <condição>; <passo>) <corpo>
 *   - init:     executado uma vez antes do loop
 *   - condição: verificada antes de cada iteração
 *   - passo:    executado ao final de cada iteração
 *
 * Pontos a destacar:
 * - for é preferível ao while quando o número de iterações é conhecido
 * - as três partes agrupadas deixam a lógica do loop mais legível
 * - int i declarado no for: escopo limitado ao loop (C99+)
 * - comparar estrutura com meow1.c: equivalentes, mas for é mais idiomático
 */
#include <stdio.h>

int main(void) {

  for (int i = 0; i < 3; i++)
    printf("meow\n");
}
