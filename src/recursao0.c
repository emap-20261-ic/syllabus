#include <stdio.h>

// fatorial: o exemplo canonico de recursao
//
//   caso base:      fat(0) = fat(1) = 1
//   caso recursivo: fat(n) = n * fat(n - 1)

int fat(int n) {
  if (n <= 1) return 1;
  return n * fat(n - 1);
}

int main(void) {
  for (int i = 0; i <= 6; i++)
    printf("fat(%d) = %d\n", i, fat(i));
}
