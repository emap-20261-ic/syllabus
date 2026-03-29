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

  /* Vou usar 4 bits para determinar as condições necessárias da
   senha. Sejam os bits ABCD. O bit A indicará a presença de uma letra
   maiuscula. O bit B indicará a presença de uma letra minúscula. O
   bit C de um algarismo. O bit D de um símbolo qualquer. */
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
