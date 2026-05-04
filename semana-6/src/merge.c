/*
  code adapted from
  https://rosettacode.org/wiki/Sorting_algorithms/Merge_sort#C

  - using STDERR for debug output
  - if called as ./sort alone, Ctrl+D terminates input.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10000


void merge (int ns[], int l, int m, int u) {
  fprintf(stderr, "debug: merge l=%d m=%d u=%d\n", l, m, u);
  int t[u - l + 1];
  for (int k = 0, a = l, b = m + 1; k < (u - l + 1); k++) {
    t[k] =  (a > m ? ns[b++]      // left list empty
	     :  (b > u ? ns[a++]  // right list empty
		 : (ns[a] < ns[b] ? ns[a++] : ns[b++])));
  }

  for (int i = l; i <= u; i++)
    ns[i] = t[i - l];
}


void merge_sort (int ns[], int i, int j) {
  fprintf(stderr, "debug: merge_sort i=%d j=%d\n", i, j);
  if ((j - i) == 0)
    return;

  int m = (i + j) / 2;
  merge_sort(ns, i, m);
  merge_sort(ns, m + 1, j);
  merge(ns, i, m, j);
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
  merge_sort(numbers, 0, n - 1);
  
  // return the result
  for (int i = 0; i < n; i++)
    printf("%d\n", numbers[i]);
  
  return 0;
}

