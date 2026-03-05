#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

typedef char* string;

int get_size(void);
void print_grid(int n);


int main() {
  int n = get_size();
  print_grid(n);
}


int get_size() {
  int n, d;
  char c = '0';
  while(true) {
    printf("width: ");
    d = scanf("%d", &n);
    printf("> d = %d n = %d\n", d, n);
    if ( d == 1 && n > 1 && n < 100 )
      break;
    if (d == 0) {
      do {
        c = getchar();
      }
      while (!isdigit(c));
      ungetc(c, stdin);
    }
  }
  return n;
}

void print_grid(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("#");
    }
    printf("\n");
  }
}
