#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  
  printf("Output: ");
  for (int i = 0, n = strlen(argv[1]); i < n; i++)
    printf("%c", argv[1][i]);
  
  printf("\n");
}
