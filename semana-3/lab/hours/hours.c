#include <ctype.h>
#include <stdio.h>

// don't touch
typedef char* string;

float calc_hours(int hours[], int weeks, char output) {
  // complete
  return 0;
}

int get_int(string prompt) {
  int n;
  printf("%s", prompt);
  scanf("%d", &n);
  return n;
}

int main(void) {
  
    int weeks = get_int("número de semanas: ");
    int hours[weeks];

    char buffer[100];
    for (int i = 0; i < weeks; i++) {
      sprintf(buffer, "semana %d: ", i+1);
      hours[i] = get_int(buffer);
    }

    char output, c;
    do {
      printf("entre T ou M: ");

      // discard
      while((c = getchar()) != '\n' && c != EOF) ;
	
      c = getchar();
      output = toupper(c);
    }
    while (output != 'T' && output != 'M');
    
    printf("%.1f hours\n", calc_hours(hours, weeks, output));
}

