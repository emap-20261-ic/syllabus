#include <stdio.h>

typedef char* string;

int main(void) {
  string names[] = {"Bill", "Charlie", "Fred",
		    "George", "Ginny", "Percy",
		    "Ron"};
  
  for (int i = 0; i < 7; i++) {
    if (names[i] == "Ron") {  // BUG
      printf("Found\n");
      return 0;
    }
  }
  printf("Not found\n");
  return 1;
}
