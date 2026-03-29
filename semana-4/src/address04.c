#include <stdio.h>

int main(void) {
  char *s = "HI!";
  printf("%c = %c = %c\n", *s, *(s + 0), s[0]);
  printf("%c = %c\n"     ,     *(s + 1), s[1]);
  printf("%c = %c\n"     ,     *(s + 2), s[2]);
}
