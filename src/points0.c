#include <stdio.h>

int main(void) {
  int points;
  printf("How many points? ");
  scanf("%d", &points);
  
  if (points < 2) {
    printf("You lost fewer than me.\n");
  }
  else if (points > 2) {
    printf("You lost more than me.\n");
  }
  else if (points == 2) {
    printf("We lost the same.\n");
  }
}
