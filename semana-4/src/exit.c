#include <stdio.h>

typedef char* string;

int main(int argc, string argv[]) {
  
    if (argc != 2) {
      printf("Missing arguments\n");
      return 1;
    }
    
    printf("hello, %s\n", argv[1]);
    return 0;
}
