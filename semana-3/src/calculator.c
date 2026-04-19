#include <stdio.h>
#include <stdlib.h>

long add(long a, long b);
long subtract(long a, long b);
int calc(char op, long a, long b, long* result);

int main(void)
{
  long x = 0, y = 0, result = 0;
  char op = 'a';

  // get input data

  printf("x: ");
  scanf("%ld", &x);
  
  printf("y: ");
  scanf("%ld", &y);

  printf("operation [a|s]: ");
  scanf(" %c", &op);

  // validating and processing
  int status = calc(op, x, y, &result);
  if (status == 0){
    printf("result = %ld\n", result);
    return EXIT_SUCCESS;
  }
  else { 
    printf("Invalid Operation\n");
    return EXIT_FAILURE;
  }

}

int calc(char op, long a, long b, long* r){
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


long add(long a, long b) { 
  return a + b;
}

long subtract(long a, long b) {
  return a - b;
}
