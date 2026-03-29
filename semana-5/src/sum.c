#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  if(argc < 2) {
    printf("usage: %s N\n", argv[0]);
    return 1;
  }
    
  long n = atol(argv[1]);
  long s = 0;
  
  for(int i = 0; i < n; i++) 
    s += i;
  printf("sum = %ld\n", s);
}  
