#include <stdio.h>

// soma 1 + 2 + ... + n: mesmo padrao do fatorial, operacao diferente
//
//   caso base:      soma_ate(0) = 0
//   caso recursivo: soma_ate(n) = n + soma_ate(n - 1)

int soma_ate(int n) {
  if (n <= 0) return 0;
  return n + soma_ate(n - 1);
}

int main(void) {
  for (int i = 0; i <= 5; i++)
    printf("soma_ate(%d) = %d\n", i, soma_ate(i));
}
