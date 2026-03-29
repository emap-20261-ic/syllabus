#include <stdio.h>
#include <ctype.h>

int main(void) {

    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    char word[1024];
    int i = 0;
    int c;

    while ((c = fgetc(file)) != EOF) {
        if (isspace(c)) {
	  // just finished reading a word
	  if (i > 0) { // only print if there is something in the buffer
	    word[i] = '\0'; // terminate the string
	    printf("Word: %s\n", word);
	    i = 0; // reset index for the next word
	  }
        } else {
	  // reading a word
	  word[i++] = c;
        }
    }

    // if the file does not end with a space, print the last word
    if (i > 0) {
        word[i] = '\0';
        printf("Word: %s\n", word);
    }

    fclose(file);
    return 0;
}

