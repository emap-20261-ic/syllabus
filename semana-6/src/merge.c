/*
  code adapted from
  https://rosettacode.org/wiki/Sorting_algorithms/Merge_sort#C

  - versão interativa e recursiva do merge
  - uso do STDERR para debug
  - se chamar ./sort apenas, Ctrl+D interrompe entrada.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10000


void merge_i (int ns[], int l, int m, int u, int c) {
  fprintf(stderr, "debug[%d]: merge_i l=%d m=%d u=%d\n", c, l, m, u);
  int t[u - l + 1];
  for (int k = 0, a = l, b = m + 1; k < (u - l + 1); k++) {
    t[k] =  (a > m ? ns[b++]      // lista esq vazia
	     :  (b > u ? ns[a++]  // lista dir vazia
		 : (ns[a] < ns[b] ? ns[a++] : ns[b++])));
  }

  for (int i = l; i <= u; i++)
    ns[i] = t[i - l];
}


void merge_aux (int ns[], int t[], int l, int m, int u, int k, int a, int b) {
  fprintf(stderr, "debug: merge_aux l=%d m=%d u=%d k=%d a=%d b=%d\n",
	  l, m, u, k, a, b);

  t[k++] = a > m ? ns[b++]
         : b > u ? ns[a++]
         : ns[a] < ns[b] ? ns[a++] : ns[b++];

  if(k < u - l + 1)
    merge_aux(ns, t, l, m, u, k, a, b);
}

void merge_r (int ns[], int l, int m, int u) {
  fprintf(stderr, "debug: merge_r l=%d m=%d u=%d\n", l, m, u);
  int t[u - l + 1];
  merge_aux(ns, t, l, m, u, 0, l, m + 1);
  for (int i = l; i <= u; i++)
    ns[i] = t[i - l];
}


void merge_sort (int ns[], int i, int j, int c) {
  fprintf(stderr, "debug[%d]: merge_sort i=%d j=%d\n", c, i, j);
  if ((j - i) == 0)
    return; // empty list
  
  int m = (i + j) / 2;
  merge_sort(ns, i, m, c + 1);
  merge_sort(ns, m + 1, j, c + 1);  
  merge_i(ns, i, m, j, c + 1);
}


int main (int argc, char* argv[]) {

  // creating the array
  int size = MAX_SIZE;
  if (argc > 1) 
    size = atoi(argv[1]);
  int numbers[size];

  // reading the file
  int number, n = 0;
  while (n < size && scanf("%d", &number) == 1)
    numbers[n++] = number;

  // sort
  merge_sort(numbers, 0, n - 1, 0);
  
  // return the result
  for (int i = 0; i < n; i++)
    printf("%d\n", numbers[i]);
  
  return 0;
}

