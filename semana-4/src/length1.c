#include <stdio.h>

int string_length(char s[]) {
  int n = 0;
  while (s[n] != 0) n++;
  return n;
}

int main(int argc, char *argv[]) {

  int length = string_length(argv[1]);
  printf("%i\n", length);

}

