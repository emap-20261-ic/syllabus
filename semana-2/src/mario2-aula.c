/*
 * Mario: do-while para validar entrada do usuário.
 *
 * Pontos a destacar:
 * - do-while: pede o tamanho ao menos uma vez, repete se n < 1
 * - testar com entradas inválidas: 0, -1, 100, 'a', "a10", "10a"
 * - comportamento do scanf com entrada não-numérica:
 *   tenta ler um inteiro; se falhar (ex: 'a'), retorna 0
 *   o valor em memória de n pode ser lixo
 *   o caractere não consumido fica no buffer → pode causar loop infinito
 *   solução robusta será vista mais adiante
 * - for após o do-while: agora n é garantidamente >= 1
 * - printf("?") sem \n: imprime na mesma linha
 * - printf("\n") ao final: quebra a linha
 */
#include <stdio.h>

int main(void) {

  int n;
  do {
      printf("width: "); scanf("%d", &n);
  }
  while (n < 1);

  for (int i = 0; i < n; i++) {
    printf("?");
  }
  printf("\n");
}
