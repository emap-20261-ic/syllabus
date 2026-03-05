#include <stdio.h>

int main(void) {
  // prompt user to agree
  char c;
  printf("Do you agree? ");
  scanf("%c", &c);

  // check whether agreed
  if (c == 'Y' || c == 'y')
    printf("Agreed.\n");
  else if (c == 'N' || c == 'n')
    printf("Not agreed.\n");
}
