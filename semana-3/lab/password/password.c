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
  
  printf("Enter your password (no spaces): ");
  scanf("%s", str);
  
  if (valid(str)) {
    printf("Strong password!\n");
  }
  else {
    printf("Weak password! Try again.\n");
  }

  return 0;
}

