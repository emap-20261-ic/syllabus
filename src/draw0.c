#include <stdlib.h>
#include <stdio.h>

void draw(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i + 1; j++)
      printf("#");
    printf("\n");
  }
}
  
int main(int argc, char *argv[]) {
  int height = atoi(argv[1]);
  draw(height);
}
