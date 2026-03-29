#include <stdio.h>
#include <stdlib.h>

void factorial(int n,int *f) {
  
  *f = 1;
  for(int i = 1; i <= n; i++) 
    *f = *f * i;
}


int main(int argc, char *argv[]) {

  // Check that only one argument was passed
  if (argc != 2) { 
    printf("Usage: %s <integer>\n", argv[0]);
    return 1;
  }

  // convert argument to integer
  int n = atoi(argv[1]);
  int f;

  factorial(n, &f);

  printf("fact %d = %d\n", n, f);
  return 0;
}

