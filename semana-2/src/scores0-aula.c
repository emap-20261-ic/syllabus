/*
 * Armadilha clássica: divisão inteira e especificador errado.
 *
 * Pontos a destacar:
 * - perguntar antes de compilar: o que será impresso?
 * - compilar com -Wall: o compilador avisa sobre o tipo errado em printf
 * - (score1+score2+score3) é int+int+int = int
 * - int / 3.0 → o literal 3.0 é double, então o int é promovido: resultado double
 * - mas %d espera int — comportamento indefinido, saída será lixo
 * - corrigir: trocar %d por %f (ou %lf) OU usar /3 (inteiro) e aceitar truncamento
 * - lição: o especificador de formato DEVE corresponder ao tipo da expressão
 * - nota: o tema "divisão inteira" volta em calculator3.c (slides-24)
 *   com foco diferente: cast explícito como solução
 */
#include <stdio.h>

int main(void) {

    int score1 = 72;
    int score2 = 73;
    int score3 = 33;

    printf("Average: %d\n",
	   (score1 + score2 + score3) / 3.0);
}
