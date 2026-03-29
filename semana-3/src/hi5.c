#include <stdio.h>

int main(void) {

  char s[] = "HI!";  
  char t[] = {'B','y','e', '!'};
  
  // what is wrong?
  for(int i = 0; i < 4; i++) 
    printf("loc s[%d] = %c %p\n", i, s[i], &s[i]);
  for(int i = 0; i < 4; i++) 
    printf("loc t[%d] = %c %p\n", i, t[i], &t[i]);
  
  printf("%s and %s \n", t, s);
}
