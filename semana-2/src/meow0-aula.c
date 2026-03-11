/*
 * Motivação para repetição: código duplicado é péssimo estilo.
 *
 * Pontos a destacar:
 * - perguntar: e se quisermos 100 meows? 1000?
 * - código duplicado é difícil de manter: se mudarmos "meow" para "woof",
 *   temos que alterar em múltiplos lugares
 * - solução: estruturas de repetição (while, for, do-while)
 */
#include <stdio.h>

int main(void)
{
    printf("meow\n");
    printf("meow\n");
    printf("meow\n");
}
