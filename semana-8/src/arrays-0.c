#include <stdio.h>

void print_array(char *msg, int a[], int size){
  printf("%s:\n", msg);
  for (int i = 0; i < size; i++)
    printf("list[%d] = %d at %p\n", i, a[i], &a[i]);
}  

int main(void) {

  int list[3];
  list[0] = 1;
  list[1] = 2;
  list[2] = 3;

  print_array("array list", list, 3);

  int new[10];
  for (int i = 0; i < 10; i++)
    new[i] = i < 3 ? list[i] : 0;

  // new = list; does not work

  print_array("array new", new, 10);
}
