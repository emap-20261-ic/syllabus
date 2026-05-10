#include <stdio.h>
#include <stdlib.h>

typedef char* string;

long int test(int n) {
  return test(n);
}

long int fatorial(int n) {
  if( n <= 0 )
    return 1;
  else
    return n * fatorial(n - 1);
}

long int fib0(int n) {
  if( n == 1 || n == 2)
    return 1;
  else
    return fib0(n - 1) + fib0(n - 2);
}

long int fib1(int n, int a, int b) {
  return (--n > 0) ? fib1(n, b, a + b) : a ;
}

long int fib2(int n, int a, int b) {
  if (--n > 0)
    return fib1(n, b, a + b); // tail recursion 
  else
    return a;
}

long int fib(int n) {
  return fib1(n, 1, 1);
}


int main(int argc, string argv[]) {

  printf("%ld\n", fatorial(atoi(argv[1])));
  
}
