#include <stdio.h>

int main(void) {
  
  char answer[20];

  printf("What's your name? ");
  scanf("%s", answer);
  
  printf("hello, %s\n", answer);
}
