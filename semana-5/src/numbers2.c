#include <stdlib.h>
#include <stdio.h>

typedef char* string;

int binary_search(int a[], int n, int x) {
  int low = 0, high = n - 1;
  while (low <= high) {
    int k = (high + low) / 2;
    if      (a[k] == x) return k;
    else if (a[k] <  x) low  = k + 1;
    else                high = k - 1;
  }
  return -1;
}

int main(int argc, string argv[]) {
  int q, a[] = {-31, 0, 1, 2, 2, 2, 2, 4, 65, 83, 99, 782};
  
  if (argc > 1) q = atoi(argv[1]);
  else          return 1;

  int n = sizeof(a)/sizeof(a[0]), i = binary_search(a, n, q);
  if (i >= 0) {
    printf("%d is at index %d.\n", q, i);
    return 0;
  }
  else {
    printf("%d is not found.\n", q);
    return 2;
  }
}
