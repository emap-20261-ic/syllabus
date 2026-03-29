#include <stdio.h>

void foo() {
  char *p = "Hello World!";
  char **p1 = &p;
  
  printf("%s %p\n", *p1, &p1);
  printf("%s %p\n", p, &p);
}

int main(int argc, char **argv) {
  foo();
  return 0;
}
