#include <stdio.h>
#include <stdlib.h>

typedef char* string;

int main(int argc, string argv[]) {
  
  int n;
  if (argc != 2) {
    printf("Usage: %s NUMBER\n", argv[0]);
    return 1;
  } else 
    n = atoi(argv[1]);

  if (n % 2 == 0) 
    printf("even\n");
  else 
    printf("odd\n");

}
