#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>

// don't touch
typedef char* string;


// used to DEBUG 
void print_bits(unsigned char x) {
  int i;
  for (i = CHAR_BIT - 1; i >= 0; i--)
    putchar(x & (1u << i) ? '1' : '0');
  
}

bool valid(string password) {

  /* Use 4 bits to track the required password conditions (ABCD):
     bit A: uppercase letter present; bit B: lowercase letter present;
     bit C: digit present; bit D: symbol present. */
  unsigned char condition = 0b0000;

  for(int i = 0; password[i] != '\0'; i++) {
    
    char c = password[i];
    
    if ( isupper(c) )                   condition |= 0b1000;
    else if ( islower(c) )              condition |= 0b0100;
    else if ( isdigit(c) )              condition |= 0b0010;
    else if (isgraph(c) && !isalnum(c)) condition |= 0b0001;

    if ((condition & 0b1111) == 0b1111)
      return true;
  }

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
