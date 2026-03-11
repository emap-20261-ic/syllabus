/*
 * Divisão inteira e imprecisão de ponto flutuante.
 *
 * Pontos a destacar:
 * - int / int = int (truncado): a divisão ocorre ANTES da conversão para float
 *   float z = 2 / 3 → z = 0.0 (não 0.666...)
 * - solução: cast explícito antes da divisão:
 *   float z = (float) x / (float) y;
 *   basta um operando ser float para a divisão ser float
 * - testar com x=2, y=3 → saída mostra imprecisão de ponto flutuante:
 *   0.66666668... (não 0.66666666...)
 * - isso não é bug: é a limitação do IEEE 754 (representação binária finita)
 * - a linha comentada mostra a correção com cast
 */
// division with integers, demonstrating truncation
#include <stdio.h>

int main(void)
{
  int x, y;

  printf("x: "); scanf("%d", &x);
  printf("y: "); scanf("%d", &y);

  float z = x / y; 
  // float z = (float) x / (float) y;
  printf("%f\n", z);
}
