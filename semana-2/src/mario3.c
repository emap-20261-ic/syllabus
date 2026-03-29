#include <stdio.h>

int main(void)
{
  // input
  int n;
  do {
    printf("size: "); scanf("%d", &n);
  } while (n < 1);

  // output
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      printf("#");
    printf("\n");
  }
}
