#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 10000
#define MAX_LENGTH 256

void bubble_sort (int a[], int n) {
  int i, t;
  bool s = true;
  while (s) {
    s = false;
    for (i = 1; i < n; i++) {
      if (a[i] < a[i - 1]) {
        t = a[i];
        a[i] = a[i - 1];
        a[i - 1] = t;
        s = true;
      }
    }
    n--;
  }
}


int main (int argc, char* argv[]) {

  // creating the array
  int size = MAX_SIZE;
  if (argc > 1) 
    size = atoi(argv[1]);
  int numbers[size];

  // reading the file
  char line[MAX_LENGTH];
  int n = 0;
  while (n < size && fgets(line, sizeof(line), stdin) != NULL) {
    int number = atoi(line);
    numbers[n++] = number;
  }

  // sort
  bubble_sort(numbers, n);

  // return the result
  for (int i = 0; i < n; i++)
    printf("%d\n", numbers[i]);
  
  return 0;
}


