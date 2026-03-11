/*
 * Equação do segundo grau: primeiro exemplo completo com if/else if/else.
 *
 * Pontos a destacar:
 * - #include <math.h> para pow() e sqrt(); compilar com flag -lm
 * - leitura de double: scanf com %lf (não %f), printf com %lf
 * - estrutura if / else if / else: apenas um bloco é executado
 * - declaração de variável DENTRO do bloco: escopo local ao bloco
 * - delta == 0 com double é problemático (imprecisão float) — mencionar brevemente
 * - return 0 ao final: convenção de sucesso
 */
#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c, delta;

    printf("a: "); scanf("%lf", &a);
    printf("b: "); scanf("%lf", &b);
    printf("c: "); scanf("%lf", &c);
    delta = pow(b, 2) - 4 * a * c;

    if (delta < 0)
      printf("Nao existem raizes reais\n");
    else if (delta == 0) {
      double x = - b / (2 * a);
      printf("X1 = X2 = %lf\n", x);
    } else {
      double x1 = (-b + sqrt(delta)) / (2 * a);
      double x2 = (-b - sqrt(delta)) / (2 * a);
      printf("X1 = %lf, X2 = %lf\n", x1, x2);
    }
    return 0;
}
