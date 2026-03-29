#include <stdio.h>

int main(void) {
  
  char *s = "HI!";
  printf("%c  at %p\n", s[0], &s[0]);
  printf("%c  at %p\n", s[1], &s[1]);
  printf("%c  at %p\n", s[2], &s[2]);
  printf("\\0 at %p\n", &s[3]);
}
