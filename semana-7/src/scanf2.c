#include <stdio.h>
#include <stdlib.h>

// segmentation fault

int main(int argc, char *argv[]) {
  char *s = malloc(10);  
  //char s[10]; 
  printf("s: ");
  scanf("%s", s);
  //fgets(s, 10, stdin);
  printf("s: %s\n", s);
  free(s);
}

