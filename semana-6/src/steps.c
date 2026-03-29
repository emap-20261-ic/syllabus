#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
    
  for(int i=0; i < 100; i++) {
    if( i >= atoi(argv[1]) )
       break;
    printf("%d ", i);
  }

  // equivalente?
  for(int i = 0, j = atoi(argv[1]); i < j && i < 100 ; i++) {
    printf("%d ", i);
  }
  
  return 0;

}  

