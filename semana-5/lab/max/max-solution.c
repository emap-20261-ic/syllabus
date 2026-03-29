#include <stdio.h>
#include <stdlib.h>

// don't touch
typedef char* string;


int max(int array[], int n) {

  int pos = 0;
  for(int i = 0; i < n; i++) {
    if(array[pos] < array[i])
      pos = i;
  }

  return pos;
}

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");

    if (!fp) {
      printf("Error: cannot open file %s\n", argv[1]);
      return 1;
    }

    char str[100];
    int size;

    // read the first line to get the number of numbers to read
    fgets(str, sizeof(str), fp);
    size = atoi(str);

    int numbers[size];

    // read the numbers from the file and store them in the array    
    for (int i = 0; i < size; i++) {
      fgets(str, sizeof(str), fp);
      numbers[i] = atoi(str);
    }
    // close the file
    fclose(fp);

    int n = max(numbers, size);
    printf("size: %d\n max: %d\n pos: %d\n", size, numbers[n], n);

    return 0;
}
