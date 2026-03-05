#include <stdio.h>
#include <stdbool.h>

typedef char* string;

bool prime(int number);
int get_int(string prompt);

int main(void) {
  
  int min, max;
  
  do {
    min = get_int("Minimum: ");
  } while (min < 1);

  do {
    max = get_int("Maximum: ");
  } while (min >= max);
    
  for (int i = min; i <= max; i++) {
    if (prime(i)) {
      printf("%i\n", i);
    }
  }
}


bool prime(int number)
{
  bool flag = true;
  
  for (int i = 2; i < (number - 1); i++) {
    if (number % i == 0) {
      flag = false;
      break;
    }
  }

  if (number <= 1)
    flag = false;
  
  return flag;
}


int get_int(string prompt)
{
  int tmp;
  printf("%s", prompt);
  scanf("%i", &tmp);
  return tmp;
}  
