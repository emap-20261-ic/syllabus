#include <stdio.h>
#include <stdlib.h>

int main(void) {

  int *x = NULL;
  int *y = NULL;
  x = malloc(sizeof(int));
  
  *x = 42;
  *y = 13;    
  y = x;        
  *y = 13;
  
  printf("teste x->%p y->%p x=%d y=%d\n", x, y, *x, *y);
  free(x);
  printf("teste x->%p y->%p x=%d y=%d\n", x, y, *x, *y);
}
