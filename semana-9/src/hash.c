#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORD 100

/* https://www.youtube.com/watch?v=2Ti5yvumFTU */
  
unsigned int hash (char *name, int table_size) {
  int length = strnlen(name, MAX_WORD);
  unsigned int hash_value = 0;
  for (int i=0; i < length; i++) {
    hash_value += name [i];
    hash_value = (hash_value * name[i]) % table_size;
  }
  return hash_value;
}


int main(int argc, char **argv) {

    if (argc < 3) {
      printf("Usage: %s filename tablesize\n", argv[0]);
      return 1;
    }

    int table_size = atoi(argv[2]);

    FILE *infile = fopen(argv[1], "r");
    if (!infile) {
      printf("Error opening file!\n");
      return 1;
    }

    char  word[MAX_WORD];
    
    while (fgets(word, MAX_WORD, infile) != NULL) {

      // removing the end-line
      word[strcspn(word, "\n")] = '\0';
      printf("%d\n", hash(word, table_size));
      
    }

    fclose(infile);
    return 0;
}
