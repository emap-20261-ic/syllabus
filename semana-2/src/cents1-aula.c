/*
 * Solução para imprecisão float: função round().
 *
 * Pontos a destacar:
 * - #include <math.h> e flag -lm para compilar
 * - round(x): arredonda para o inteiro mais próximo (retorna double)
 * - round(4.19999... * 100) = round(419.9999...) = 420.0 → int: 420
 * - testar com os mesmos valores de cents0.c: agora 4.20 → 420 ✓
 * - round() vs truncamento: sem round, 419.999 → 419; com round → 420
 * - lição: ao trabalhar com valores monetários, cuidado com float;
 *   alternativa robusta: trabalhar sempre em centavos (inteiros)
 */
#include <math.h>
#include <stdio.h>

int main(void)
{
    float amount;
    printf("Dollar amount: ");
    scanf("%f", &amount);

    int cents = round(amount * 100);
    printf("Cents: %i\n", cents);
}
