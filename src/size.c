#include <stdio.h>
 
int main(int argc, char* argv[]) {
  
  float v;
  
  printf(" char .......: %lu bytes\n", sizeof(char));
  printf(" short.......: %lu bytes\n", sizeof(short));
  printf(" int.........: %lu bytes\n", sizeof(int));
  printf(" long........: %lu bytes\n", sizeof(long));
  printf(" float ......: %lu bytes\n", sizeof(float));
  printf(" double......: %lu bytes\n", sizeof(double));
  printf(" long double.: %lu bytes\n", sizeof(long double));
  printf(" v ocupa.....: %lu bytes\n", sizeof(v));

  return 0;
}