#include <stdio.h>
#include <stdlib.h>


void factorial(int n,int *f) {

  // complete
  
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

  // call factorial and print the result

  return 0;
}

