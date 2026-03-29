#include <stdio.h>

typedef char* string;

int main(int argc, string argv[]) {

  if (argc == 2)
    printf("hello %s, I am %s.\n",
	   argv[1], argv[0]);
  else
    printf("hello, I am %s\n", argv[0]);

}
