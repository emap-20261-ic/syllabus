#include <stdio.h>

int getvalue(void) {
  int tmp;
  printf("score: "); scanf("%d", &tmp);
  return tmp;
}

int main(void) {
  
  int score1 = getvalue();
  int score2 = getvalue();
  int score3 = getvalue();
  
  printf("Average: %f\n", (score1 + score2 + score3) / 3.0);
}
