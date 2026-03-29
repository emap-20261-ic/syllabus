#include <stdio.h>
#include <stdlib.h>

// don't touch
typedef char* string;


void max(int a[], int n) {

  // TODO complete aqui seu código. a[] é o array passado e n é o
  // tamanho.
  
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

    // reading the size
    fgets(str, sizeof(str), fp);
    size = atoi(str);

    int numbers[size];

    // reading the numbers and closing the file
    for (int i = 0; i < size; i++) {
      fgets(str, sizeof(str), fp);
      numbers[i] = atoi(str);
    }
    fclose(fp);

    // TODO produza a saida esperada
    max(numbers, size);
    
    return 0;
}
