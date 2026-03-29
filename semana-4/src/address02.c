#include <stdio.h>
#include <string.h>

typedef char* string;

int main(void) {

  char s[] = "Hello";
  char *t  = "Hello", *m = "World"; // it does not work with 'char* t = ..., m = ...'
  string u = "Ola", v = "Mundo";    // why it works?!

  int a   = 12; // declare a and put the value 12 on it
  int *pa = &a; // pa is a pointer to int, put the address of a on it
  *pa     = 24; // update the place pointed by pa to 24

  /* error: incompatible integer to pointer conversion initializing
     'int *' with an expression of type 'int' [-Wint-conversion] 
     
  int *pb = 24;  // declare a pointer to int but put a int value on it place.

  */
    
  printf("%s at %p %lu\n", s, s, strlen(s));
  printf("%s at %p %lu\n", t, t, strlen(t));
  printf("%s at %p %lu\n", m, m, strlen(m));
  printf("%s at %p %lu\n", u, u, strlen(u));
  printf("%s at %p %lu\n", v, v, strlen(v));
}
