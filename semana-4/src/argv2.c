#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {

  int a[3][2] = { { 2 , 10}, { 1, 5 }, {4 , 2} };
  printf("a[%d] = %d\n", 5, a[1][1]);

  for (int i = 0; i < argc; i++) {
    printf("%s\n", argv[i]);
  }
  
  for (int i = 0; i < argc; i++) {
    for (int j = 0, n = strlen(argv[i]); j < n; j++) {
      printf("%c\n", argv[i][j]);
    }
    printf("\n");
  }
}
