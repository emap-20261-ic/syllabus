#include <stdio.h>
#include <string.h>

int main(void) {

  char *s = "hello";
  char *t = "hello";

  printf("s = %p  t = %p\n", s, t);
  printf("%s\n", strcmp(s,t) == 0 ? "same" : "different");
}
