#include <stdio.h>

// fatorial com acumulador (tail recursion)
//
// Compare com recursao0.c: o resultado parcial e carregado no parametro
// `acc`, entao a chamada recursiva e a ULTIMA operacao da funcao (nao
// ha multiplicacao esperando o retorno como em `n * fat(n - 1)`).
//
// Compiladores podem otimizar essa forma para uma iteracao -- o stack
// nao cresce com n. Mesmo principio do `fib_aux` em math.c.

int fat_aux(int n, int acc) {
  if (n <= 1) return acc;
  return fat_aux(n - 1, n * acc);
}

int fat(int n) {
  return fat_aux(n, 1);
}

int main(void) {
  for (int i = 0; i <= 6; i++)
    printf("fat(%d) = %d\n", i, fat(i));
}
