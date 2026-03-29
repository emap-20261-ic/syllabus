#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

int main(void) {
  int n, d;
  char c = '0';
  
  while(true) {
    printf("width: ");
    d = scanf("%d", &n);
    printf("debug> d = %d n = %d\n", d, n);
    if ( d == 1 && n > 1 && n < 100 )
      break;
    if (d == 0) {
      do 
        c = getchar();
      while (!isdigit(c));
      ungetc(c, stdin);
    }
  }
  
  for (int i = 0; i < n; i++)
    printf("?");
  printf("\n");
}
