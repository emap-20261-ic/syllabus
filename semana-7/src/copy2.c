#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  const char *s = "hi!"; // char s[] = "hi!";
  char *t = malloc(strlen(s) + 1);
  // char *t = NULL;

  printf("1 t = %p\n", t);
  strcpy(t, s);
  printf("2 t = %p\n", t);

  t[0] = toupper(t[0]);

  printf("s: %s\nt: %s\n", s, t);
  free(t);
  return 0;
}
