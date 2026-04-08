#include <stdio.h>
#include <string.h>


int my_strcmp(char *a, char *b) {
  while ((*a != '\0' && *b != '\0') && *a == *b) {
    printf(".");
    a++;
    b++;
  }
  return (*a - *b);
}

int main(void) {

  char s[100];
  char t[100];

  printf("s: "); scanf("%s", s);
  printf("t: "); scanf("%s", t);

  // print strings
  printf("%s at %p\n", s, s);
  printf("%s at %p\n", t, t);
  printf("my_string = %d\n", my_strcmp(s, t) );
  printf("   strcmp = %d\n", strcmp(s, t) );  
}
