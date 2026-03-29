#include <stdio.h>

int main(void) {

  int n;
  do {
      printf("width: "); scanf("%d", &n);
  }
  while (n < 1);

  for (int i = 0; i < n; i++) {
    printf("?");
  }
  printf("\n");
}
