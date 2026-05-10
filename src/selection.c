#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 10000


void print_array(int a[], int n, char sep) {
  for (int i = 0; i < n; i++)
    printf("%d%c", a[i], sep);
}


void selection_sort (int a[], int n) {
  for (int i = 0, m, t; i < n; i++) {
    m = i;
    for (int j = i; j < n; j++) {
      if (a[j] < a[m]) m = j;
    }
    // swap values
    t = a[i]; a[i] = a[m]; a[m] = t;
  }
}


int main (int argc, char* argv[]) {

  // creating the array
  int size = MAX_SIZE;
  if (argc > 1) 
    size = atoi(argv[1]);
  int numbers[size];

  // reading the file
  int number, n = 0;
  while (n < size && scanf("%d", &number) == 1) 
    numbers[n++] = number;

  // sort
  selection_sort(numbers, n);

  // return de result
  print_array(numbers, n, '\n');
  
  return 0;
}
