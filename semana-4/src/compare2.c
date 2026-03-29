#include <stdio.h>
#include <string.h>

int main(void) {

  char s[100];
  char t[100];

  printf("s: "); scanf("%s", s);
  printf("t: "); scanf("%s", t);
  
  // print strings
  printf("%s at %p\n", s, s);
  printf("%s at %p\n", t, t);
  printf("%s\n", strcmp(s,t) == 0 ? "same" : "different");
}
