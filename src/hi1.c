#include <stdio.h>

int main(void) {

  char a[] = "HI!";
  char b[] = {'H', 'I', '!', '\0'};

  printf("%s vs %s\n", a, b);

  // acesso a cada char por indice -- note o '\0' final em a[3]
  for (int i = 0; i < 4; i++) {
    printf("a[%d] = %c (%i)\n", i, a[i], a[i]);
  }
}
