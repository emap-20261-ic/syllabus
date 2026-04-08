#include <stdio.h>


int main(void) {

  char s[100];
  char t[100];

  printf("s: "); scanf("%s", s);
  printf("t: "); scanf("%s", t);

  // so compiler don't see s == t
  char *a = s;
  char *b = t;

  printf("%s\n",  a == b  ? "same" : "different");
  printf("%s\n", *a == *b ? "same" : "different");
}
