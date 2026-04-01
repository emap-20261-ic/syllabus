#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {

  if (argc != 2) {
    printf("usage: %s <n>\n", argv[0]);
    return 1;
  }

  int n = atoi(argv[1]);
  int scores[n]; 
  int total = 0;
  
  for(int i = 0; i < n; i++) {
    printf("value [%d]: ", i);
    scanf("%d", &scores[i]);
    total = total + scores[i];    
  }
    
  printf("average: %f\n", total / (float) n);
}
