/*
- more operations
- integer overflow: int ~> long
- scanf behavior
- error codes
*/

#include <stdio.h>
#include <stdlib.h>

int add(int a, int b);
int subtract(int a, int b);
int calc(char op, int a, int b, int* result);

int main(void)
{
  int x = 0, y = 0, result = 0;
  char op = 'a';

  // get input data

  printf("x: ");
  scanf("%d", &x);
  
  printf("y: ");
  scanf("%d", &y);

  printf("operation [a|s]: ");
  scanf(" %c", &op);

  // validating and processing
  int status = calc(op, x, y, &result);
  if (status == 0){
    printf("result = %d\n", result);
    return EXIT_SUCCESS;
  }
  else { 
    printf("Invalid Operation\n");
    return EXIT_FAILURE;
  }

}

int calc(char op, int a, int b, int* r){
  switch (op) {
  case 'a': case 'A':
    *r = add(a, b);
    break;

  case 's': case 'S':
    *r = subtract(a, b);
    break;

  default:
    return 1;
  }
  return 0;
}


int add(int a, int b) { 
  return a + b;
}

int subtract(int a, int b) {
  return a - b;
}
