#include <stdio.h>

void swap(int* a, int* b) {
  printf("a at [%p] [%p]\n", &a, a);
  int tmp = *a; 
  *a = *b;      
  *b = tmp;     
}

int main(void) {
  int x = 1;
  int y = 2;
  
  printf("x at %p is %i, y is %i\n", &x, x, y);
  swap(&x, &y); 
  printf("x is %i, y is %i\n", x, y);
}
