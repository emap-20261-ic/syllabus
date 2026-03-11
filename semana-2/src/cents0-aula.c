/*
 * Imprecisão de ponto flutuante: o caso dos centavos.
 *
 * Pontos a destacar:
 * - perguntar antes de testar: o que será impresso para 4.20?
 * - testar: 0.99 → 99 ✓, 1.23 → 123 ✓, 4.20 → 419 ✗ (esperado: 420)
 * - causa: 4.20 não pode ser representado exatamente em binário
 *   armazenado internamente como 4.19999980...
 *   4.19999980 * 100 = 419.99998... → truncado para int → 419
 * - NÃO é um bug do C; é uma limitação fundamental de ponto flutuante (IEEE 754)
 * - solução: usar round() antes de converter para int (ver cents1.c)
 */
#include <stdio.h>

int main(void)
{
    float amount;
    printf("Dollar amount: "); scanf("%f", &amount);

    int cents = amount * 100;
    printf("Cents: %i\n", cents);
}
