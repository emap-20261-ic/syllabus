#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void) {
  char s[] = "hi!";
  char *t = s;

  // capitalize first letter in string
  if (strlen(s) > 0) {
    s[0] = toupper(s[0]);
  }
  
  printf("s: %s\n", s);
  printf("t: %s\n", t);
  return 0;
}
