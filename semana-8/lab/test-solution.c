/*
  Gabarito dos testes para o laboratório 8.

  Cobre todas as tarefas do README.org com casos extremos: listas
  vazias, unitárias, já ordenadas, em ordem inversa, com duplicatas e
  com todos os elementos iguais. Usa assert() — se algo quebrar, o
  programa aborta com a linha exata.

  Para usar este arquivo no lugar de test.c, ajuste o Makefile
  trocando test.c por test-solution.c no alvo `test`.
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"


/* checa ordem ascendente usando só a API pública */
static int is_sorted(t_node *list) {
  int n = list_size(list);
  if (n < 2) return 1;
  for (int i = 1; i < n; i++)
    if (list_nth(list, i) < list_nth(list, i - 1))
      return 0;
  return 1;
}


/* tarefa 1: list_array é o inverso de list_create */
static void test_list_array(void) {
  int in[] = {10, 20, 30, 40, 50};
  t_node *list = list_create(in, 5);

  int out[5];
  list_array(list, out, list_size(list));
  for (int i = 0; i < 5; i++) assert(out[i] == in[i]);
  list_del(list);

  /* unitária */
  int one[] = {42};
  t_node *s = list_create(one, 1);
  int oneout[1];
  list_array(s, oneout, 1);
  assert(oneout[0] == 42);
  list_del(s);

  printf("test_list_array OK\n");
}


/* tarefa 2: list_split divide ao meio; ímpar fica na primeira metade */
static void test_list_split(void) {
  /* par */
  int even[] = {1, 2, 3, 4};
  t_node *l = list_create(even, 4);
  t_node *a = NULL, *b = NULL;
  list_split(l, &a, &b);
  assert(list_size(a) == 2 && list_size(b) == 2);
  assert(list_first(a) == 1 && list_nth(a, 1) == 2);
  assert(list_first(b) == 3 && list_nth(b, 1) == 4);
  list_del(a); list_del(b);

  /* ímpar: primeira metade leva o extra */
  int odd[] = {1, 2, 3, 4, 5};
  t_node *l2 = list_create(odd, 5);
  t_node *c = NULL, *d = NULL;
  list_split(l2, &c, &d);
  assert(list_size(c) == 3 && list_size(d) == 2);
  assert(list_first(c) == 1 && list_first(d) == 4);
  list_del(c); list_del(d);

  /* caso mínimo: tamanho 2 */
  int two[] = {7, 8};
  t_node *l3 = list_create(two, 2);
  t_node *e = NULL, *f = NULL;
  list_split(l3, &e, &f);
  assert(list_size(e) == 1 && list_size(f) == 1);
  assert(list_first(e) == 7 && list_first(f) == 8);
  list_del(e); list_del(f);

  printf("test_list_split OK\n");
}


/* tarefa 3: list_hasloop detecta ciclos via Floyd */
static void test_list_hasloop(void) {
  /* sem loop, caso comum */
  int arr[] = {1, 2, 3, 4, 5};
  t_node *list = list_create(arr, 5);
  assert(list_hasloop(list) == 0);
  list_del(list);

  /* lista vazia */
  assert(list_hasloop(NULL) == 0);

  /* unitária */
  int one[] = {99};
  t_node *s = list_create(one, 1);
  assert(list_hasloop(s) == 0);
  list_del(s);

  /* com loop: nconc(a, a) liga o último->next ao head */
  int arr2[] = {1, 2, 3, 4, 5};
  t_node *loopy = list_create(arr2, 5);
  list_nconc(loopy, loopy);
  assert(list_hasloop(loopy) == 1);
  /* deliberadamente NÃO chamamos list_del(loopy): a lista é cíclica
     e o tipo t_node é opaco aqui — não há como quebrar o ciclo via
     API pública. O SO recupera a memória ao final do processo. */

  printf("test_list_hasloop OK\n");
}


/* tarefas 4 e 5: bateria parametrizada para qualquer sort in-place */
static void test_sort(void (*sort)(t_node **), const char *name) {
  /* vazia */
  t_node *empty = NULL;
  sort(&empty);
  assert(empty == NULL);

  /* unitária */
  int one[] = {7};
  t_node *s = list_create(one, 1);
  sort(&s);
  assert(list_size(s) == 1 && list_first(s) == 7);
  list_del(s);

  /* já ordenada (idempotência) */
  int sorted[] = {1, 2, 3, 4, 5};
  t_node *a = list_create(sorted, 5);
  sort(&a);
  assert(list_size(a) == 5 && is_sorted(a));
  assert(list_first(a) == 1 && list_nth(a, 4) == 5);
  list_del(a);

  /* ordem inversa (pior caso típico) */
  int rev[] = {5, 4, 3, 2, 1};
  t_node *r = list_create(rev, 5);
  sort(&r);
  assert(list_size(r) == 5 && is_sorted(r));
  list_del(r);

  /* duplicatas e ordem arbitrária */
  int dups[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
  t_node *d = list_create(dups, 11);
  sort(&d);
  assert(list_size(d) == 11 && is_sorted(d));
  assert(list_first(d) == 1);
  assert(list_nth(d, 10) == 9);
  list_del(d);

  /* todos iguais */
  int same[] = {7, 7, 7, 7};
  t_node *eq = list_create(same, 4);
  sort(&eq);
  assert(list_size(eq) == 4);
  for (int i = 0; i < 4; i++) assert(list_nth(eq, i) == 7);
  list_del(eq);

  printf("test_sort(%s) OK\n", name);
}


/* tarefa 6: list_del_rec_tc — correção + stress de pilha.

   O stress test cria uma lista de 1.000.000 nós e a libera com
   list_del_rec_tc. Esta chamada só sobrevive em duas condições
   simultâneas:

   1. A implementação está em forma tail recursive (chamada
      recursiva como última ação).
   2. O compilador aplicou TCO — em clang, isso requer pelo menos
      `-O2` (NÃO acontece em `-O0`).

   Se este teste fizer SIGSEGV (exit code 139), revise o Makefile:
   está compilando com `-O0` ou sem `-O*` algum? Ajuste para `-O2`.
   Se já está em `-O2` e ainda quebra, a implementação não está
   em posição de cauda — revise a tarefa 6. */
static void test_list_del_rec_tc(void) {
  /* sanidade em lista curta — independe de TCO */
  int small[] = {1, 2, 3, 4, 5};
  t_node *s = list_create(small, 5);
  list_del_rec_tc(s);
  printf("test_list_del_rec_tc (small) OK\n");

  /* stress: 1M nós exige TCO para não estourar a pilha */
  const int n = 1000000;
  int *arr = malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) arr[i] = i;
  t_node *big = list_create(arr, n);
  free(arr);
  list_del_rec_tc(big);
  printf("test_list_del_rec_tc (%d nós) OK — TCO ativa\n", n);
}


int main(void) {
  /* stdout sem buffer: cada printf aparece na hora, mesmo que o
     próximo teste estoure a pilha. Útil para diagnosticar qual
     teste exatamente quebrou. */
  setbuf(stdout, NULL);

  test_list_array();
  test_list_split();
  test_list_hasloop();
  test_sort(merge_sort, "merge_sort");
  test_sort(selection_sort, "selection_sort");
  test_list_del_rec_tc();  /* mantido por último: pode quebrar sem -O2 */
  printf("\nall tests passed\n");
  return 0;
}
