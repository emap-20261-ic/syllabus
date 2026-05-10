#include <stdio.h>
#include <stdlib.h>

int main(void) {

  int *a = malloc(3 * sizeof(int));
  
  a[0] = 1;
  a[1] = 2;
  a[2] = 3;
  a[3] = 4; 

  for (int i = 0; i < 4; i++)
    printf("a[%d] = %d at %p\n", i, a[i], &a[i]);

  free(a);
  return 0;
}
