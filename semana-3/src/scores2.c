#include <stdio.h>

int main(void) {

  int n = 0;
  printf("How many values? "); scanf("%d", &n);

  int scores[n]; 
  int total = 0;
  
  for(int i = 0; i < n; i++) {
    printf("value [%d]: ", i);
    scanf("%d", &scores[i]);
    total = total + scores[i];    
  }
    
  printf("average: %f\n", total / (float) n);
}
