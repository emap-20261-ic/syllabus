/*
 * Mario: laços aninhados para grade n×n.
 *
 * Pontos a destacar:
 * - dois for aninhados: loop externo (i) para linhas, interno (j) para colunas
 * - printf("#") sem \n: imprime na mesma linha
 * - printf("\n") ao final de cada linha (loop externo)
 * - cada variável de loop tem seu próprio escopo (i e j são independentes)
 * - testar: n=3 → grade 3×3; n=5 → grade 5×5
 * - desafio: como imprimir só o triângulo? (loop interno: j < i+1)
 */
#include <stdio.h>

int main(void)
{
  // leitura
  int n;
  do {
    printf("size: "); scanf("%d", &n);
  } while (n < 1);

  // producao saida
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      printf("#");
    printf("\n");
  }
}
