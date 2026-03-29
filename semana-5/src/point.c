#include <stdio.h>
#include <string.h>

typedef char* string;

typedef struct pointer {
  int x;
  int y;
} t_pointer;

int main(void) {
  t_pointer p;
  p.x = 10;
  p.y = 20;
  printf("Point: %d %d\n", p.x, p.y);
}
