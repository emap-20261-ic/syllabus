#include <stdio.h>

int main(void) {

  int m=10, n, o;
  int *z = &m;

  // z is a pointer so %p would print the address
  printf("-  z stores the address of m = %p\n",  (void*) z); 
  printf("- *z stores the   value of m = %i\n", *z);

  // &m gives the address of the integer variable m so %p is the
  // specifier for that address
  printf("- &m     is the address of m = %p\n", (void*) &m); 
  printf("- &n stores the address of n = %p\n", (void*) &n);
  printf("- &o stores the address of o = %p\n", (void*) &o);

  // &z gives the address, where the pointer z is stored -> still an
  // address -> %p is the right specifier
  printf("- &z stores the address of z = %p\n", (void*) &z); 
}
