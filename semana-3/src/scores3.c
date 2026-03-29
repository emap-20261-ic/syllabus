#include <stdio.h>
#include <stdlib.h>

typedef char* string;

int main(int argc, string argv[]) {

  int size = atoi(argv[1]);
  int total = 0, t = 0;
  
  for (int i = 0; i < size; i++) {
    printf("valor [%d]: ", i);
    scanf("%d", &t);
    total += t;
  }

  printf("total: %d\n", total);
}
