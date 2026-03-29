#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void) {
  char *s;
  char *t = s;

  printf("s:"); scanf("%s", s);
  
  // capitalize first letter in string
  if (strlen(s) > 0) {
    s[0] = toupper(s[0]);
  }
  
  printf("s: %s\n", s);
  printf("t: %s\n", t);
}
