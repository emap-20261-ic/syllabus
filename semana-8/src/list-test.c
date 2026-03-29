#include <stdio.h>
#include <stdlib.h>
#include "list.h"


int sum(int a, int b) {
  return a + b;
}

int main(int argc, char *argv[]) {

  FILE *fp;

  if(argc < 2) {
    printf("usage: %s FILE.\n", argv[0]);
    return 1;
  }

  fp = fopen(argv[1], "r");
  if (fp == NULL) {
    printf("Could not open file.\n");
    return 1;
  }

  char line[100];
  t_node *alist = NULL;

  while (fgets(line, sizeof(line), fp) != NULL) 
    alist = list_insert(atoi(line), alist);

  // problemas da reverse_rec, reverse e reverse?

  int res = list_foldr(alist, sum, 0);
  printf("a soma é = %d\n", res);

  return 0;

}
