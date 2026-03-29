#include <stdio.h>
#include <string.h>

int main(void) {
  
  char s[] = "alexandre";

  for (int i = 0; i < strlen(s); i++) {
    int c = (int) s[i];
    printf("%c %i\n", s[i], c);
  }
}
