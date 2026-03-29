#include <ctype.h> 
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {

  printf("before: %s\n", argv[1]);
  printf(" after: ");
  for (int i = 0, n = strlen(argv[1]); i < n; i++) {
    if (islower(argv[1][i])) 
      printf("%c", toupper(argv[1][i]));
    else 
      printf("%c", argv[1][i]);
  }
  printf("\n");

}
