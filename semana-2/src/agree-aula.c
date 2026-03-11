/*
 * Leitura de char e operadores lógicos.
 *
 * Pontos a destacar:
 * - tipo char: 1 byte, representa um caractere
 * - scanf("%c", &c): lê um caractere do teclado
 * - literais de char: aspas SIMPLES 'Y' (não "Y" — isso seria string)
 * - operador || (ou lógico): pelo menos uma condição deve ser verdadeira
 * - testar: Y, y, N, n, e outro caractere (nem agreed nem not agreed)
 * - o que acontece se o usuário digitar "yes"? apenas o 'y' é lido
 */
#include <stdio.h>

int main(void) {
  // prompt user to agree
  char c;
  printf("Do you agree? ");
  scanf("%c", &c);

  // check whether agreed
  if (c == 'Y' || c == 'y')
    printf("Agreed.\n");
  else if (c == 'N' || c == 'n')
    printf("Not agreed.\n");
}
