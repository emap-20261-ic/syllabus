#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

// don't touch
typedef char* string;


bool valid(string password) {
  // TODO
  return false;
}

int main(void) {

  char str[100];
  
  printf("Entre sua senha (sem espaços): ");
  scanf("%s", str);
  
  if (valid(str)) {
    printf("Sua senha é forte! Parabéns!\n");
  }
  else {
    printf("Sua senha é fraca! Tente novamente.\n");
  }

  return 0;
}

