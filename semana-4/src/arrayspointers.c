#include <stdio.h>

// call-by-value
int g(int a){
  a = a + 1;
  return a;
}

/* call-by-reference (using value of the address).
   => `a` is the pointer for the first value of `v`. */
int h(int a[]){
  a[2] = 100;
  return a[0];
}

int main(void) {

  int *r = (int[]) {10, 20, 30, 40}; // cast do tipo do literal
  int v[] = {10, 20, 30, 40};
  int *p = v;

  printf("%p\n", (void*) p);
  printf("%p\n", (void*) (p + 1));

  printf("%d\n", *p);
  printf("%d\n", *(p + 1));

  h(v);
  printf("v[%d] = %d\n", 2, v[2]);
  
}
