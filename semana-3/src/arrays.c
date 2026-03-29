#include <stdio.h>

void set_array(int array[4]) {

  printf("array[0] %p\n", &array[0]);
  array [0] = 22;
}

void set_int(int x) {

  printf("x %p\n", &x);
  x = 22;
  
}

int main(void) {
  
  int a = 10;
  int b[4] = { 0, 1, 2, 3 };

  printf("a %p\n", &a);
  printf("b[0] %p\n", &b[0]);
  
  set_int(a);

  set_array(b);
  printf("%d %d\n", a, b[0]); 
}
