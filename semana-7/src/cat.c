#include <stdio.h>

int main(int argc, char *argv[]) {

  if(argc < 2) {
    printf("Usage: %s FILE\n", argv[0]);
    return 1;
  }

  char ch;
  FILE* ptr = fopen(argv[1], "r");
  
  while((ch = fgetc(ptr)) != EOF)
    printf("%c", ch);
 
  return 0;
}
