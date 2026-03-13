#include <stdio.h>

int main(void) {
  
  int n;
  int i;
  
  do {
      printf("width: ");
      scanf("%d", &n);
  }
  while (n < 1);
  
  for (i = 0; i < n; i++) {
    printf(" %d ", i);
  }

  printf("\n\no ultimo i foi %d\n", i);
}
