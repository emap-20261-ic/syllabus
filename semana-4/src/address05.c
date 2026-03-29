#include <stdio.h>

int main(void) {
  
  char *s = "HI!";
  char c = s[0];
  char *p = &c;
  char *q = &s[0];

  printf("s at %p\n", s);
  printf("q at %p\n", q);  
  printf("p at %p\n", p);
  printf("c at %p\n", &c);

  printf(" p = %c  c = %c q = %c\n", *p, c, *q);
}
