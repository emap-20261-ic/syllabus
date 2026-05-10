#include <stdio.h>

int main(int argc, char* argv[]) {

  printf("foram %d argumentos\n", argc);

  if (argc == 2)
    printf("hello %s, I am %s.\n", argv[1], argv[0]);
  else
    printf("hello, I am %s\n", argv[0]);

}
