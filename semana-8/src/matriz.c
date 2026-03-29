#include <stdio.h>
#include <stdlib.h>

void print_matriz1(int matriz[][3], int n, int m) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j)
      printf("%d ", matriz[i][j]);
    printf("\n");
  }
}

void print_matriz2(int matriz[][10], int n, int m) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j)
      printf("%d ", matriz[i][j]);
    printf("\n");
  }
}


int main(int argc, char *argv[]) {
  int a[][3] = { 1,2,3,
		 4,5,6,
		 7,8,9 } ;

  print_matriz1(a, 3, 3);

}
  
