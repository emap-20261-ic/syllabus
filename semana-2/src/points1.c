#include <stdio.h>

int main() {
  const int MINE = 2;
    
  int points;
  printf("How many points did you lose? ");
  scanf("%d", &points);
  
  if (points < MINE)
    printf("You lost fewer points than me.\n");
  else if (points > MINE)
    printf("You lost more points than me.\n");
  else
    printf("You lost the same.\n");
}
