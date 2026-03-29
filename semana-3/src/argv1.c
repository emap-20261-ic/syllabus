#include <stdio.h>

typedef char* string;

int main(int argc, string argv[]) {
  
  for (int i = 0; i < argc; i++) {
    printf("%d = %s\n", i, argv[i]);
  }
  
}
