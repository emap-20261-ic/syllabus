#include <stdio.h>

int get_value(char prompt[]) {
  int tmp;
  do {
    printf("%s", prompt);
    scanf("%d", &tmp);
  } while (tmp <= 0);
  return tmp;
}

float average(int length, int array[])
{
  int sum = 0;
  for (int i = 0; i < length; i++)
    sum += array[i];
  return sum / (float) length;
}

int main(void)
{
  int n = get_value("How many values? ");
  int scores[n];
  for (int i = 0; i < n; i++)
    scores[i] = get_value("Score: ");

  printf("Average: %f\n", average(n, scores));
}

