#include <stdio.h>

int main(void) {
  int arr[5] = {1, 2, 3, 4, 5};
  int *p = arr;
  printf("%zu %zu %zu %zu\n", sizeof(arr), sizeof(p), sizeof(arr[0]), sizeof(*(p + 1)));
}
