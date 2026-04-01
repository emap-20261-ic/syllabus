#include <stdio.h>
#include <string.h>

typedef char* string;

int main(int argc, char *argv[]) {

  char s[] = "Hello1";
  char *t  = "Hello2", *u = "Hello3"; 
  string v = "Hello4", x = "Hello5"; // typedef is convenient

  printf("'%s' at %p has size %lu\n", t, t, strlen(t));
  printf("'%s' at %p has size %lu\n", v, v, strlen(v));
}
