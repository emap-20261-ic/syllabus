#include <stdio.h>
#include <string.h>

// don't touch
typedef char* string;

void replace(string txt, string out) {

  int i = 0;
  for ( ; txt[i] != '\0'; i++) {
    
    switch (txt[i])
      {
      case 'a':
	out[i] = '6';
	break;
	  
      case 'e':
	out[i] = '3';
	break;

      case 'i':
	out[i] = '1';
	break;

      case 'o':
	out[i] = '0';
	break;
	
      default:
	out[i] = txt[i];
      }
  }
  out[i] = '\0';
}


int main(int argc, string argv[]) {

  char buffer[100];
  memset(buffer, '\0', sizeof(buffer));
  
  if (argc != 2) {
    printf("Usage: %s <word>\n", argv[0]);
    return 1;
  }

  replace(argv[1], buffer);
  printf("%s\n", buffer);

  return 0;
}
