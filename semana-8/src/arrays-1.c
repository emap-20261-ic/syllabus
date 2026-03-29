#include <stdio.h>
#include <stdlib.h>

void print_array(char *msg, int a[], int size){
  printf("%s:\n", msg);
  for (int i = 0; i < size; i++)
    printf("list[%d] = %d at %p\n", i, a[i], &a[i]);
}  

int main(void) {

  int *list = malloc(3 * sizeof(int));
  if (list == NULL)
    return 1;
  list[0] = 1; list[1] = 2; list[2] = 3;

  print_array("list array", list, 3);
  
  int *new = malloc(10 * sizeof(int));
  if (new == NULL) {
    free(list);
    return 1;
  }

  for (int i = 0; i < 10; i++)
    new[i] = i < 3 ? list[i] : 0;
  
  free(list);
  list = new; // works fine with pointers

  print_array("new array", list, 10);

  free(list);
  return 0;
}
