#include <stdlib.h>
#include <stdio.h>

int bin_search_aux(int a[], int x, int i, int j) {
    if (j < i)
      return -1;

    int k = (j + i) / 2;
    
    if (a[k] == x)     return k;
    else if (a[k] < x) return bin_search_aux(a, x, k + 1, j);
    else               return bin_search_aux(a, x, i, k - 1);
}


int bin_search(int a[], int n, int q) {
  return bin_search_aux(a, q, 0, n - 1);
}


int main(int argc, char *argv[]) {
  int q, a[] = {-31, 0, 1, 2, 2, 4, 65, 83, 99, 782};
  
  if (argc > 1)
    q = atoi(argv[1]);
  else
    return 1;
  
  int n = sizeof a / sizeof a[0], i = bin_search(a, n, q);
  if (i >= 0) {
    printf("%d is at index %d.\n", q, i);
    return 0;
  }
  else {
    printf("%d is not found.\n", q);
    return 1;
  }
}
