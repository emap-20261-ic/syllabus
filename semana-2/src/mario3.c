#include <stdio.h>

int main(void)
{
  // leitura
  int n;
  do {
    printf("size: "); scanf("%d", &n);
  } while (n < 1);

  // producao saida
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      printf("#");
    printf("\n");
  }
}
