#include <stdio.h>
#include <stdlib.h>

typedef char* string;

int main(int argc, string argv[]) {
  int numbers[] = {4, 6, 8, 2, 7, 5, 0};

  if(argc < 2) {
    printf("Usage: %s NUMBER\n", argv[0]);
    return 1;
  }

  int t = atoi(argv[1]);
  
  for (int i = 0; i < 7; i++) {
    if (numbers[i] == t) {
      printf("Found at %d\n", i);
      return 0;
    }
  }
  printf("Not found\n");
  return 1;
}
