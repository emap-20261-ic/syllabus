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

  print_array("array list", list, 3);

  list = realloc(list, 10 * sizeof(int));
  if (list == NULL) {
    free(list);
    return 1;
  }

  print_array("array list (antes) ", list, 10);

  for (int i = 3; i < 10; i++)
    list[i] = 0;

  print_array("array list (depois)", list, 10);
  
  free(list);
  return 0;
}
