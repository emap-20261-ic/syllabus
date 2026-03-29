#include <stdio.h>

int main(int argc, char *argv[]) {

  // count up until '\0' (aka NUL or 0)
  int n = 0;
  while (argv[1][n] != 0)
    n++;
  printf("%i\n", n);
}
