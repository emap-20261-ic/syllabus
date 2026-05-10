#include <stdio.h>

int main(int argc, char *argv[]) {
  // char *s = malloc(10);  
  char s[10]; 
  printf("s: ");
  scanf("%9s", s);
  printf("s: %s\n", s);
}

