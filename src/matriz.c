#include <stdio.h>
#include <stdlib.h>

void print_matrix1(int matrix[][3], int n, int m) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j)
      printf("%d ", matrix[i][j]);
    printf("\n");
  }
}

void print_matrix2(int matrix[][10], int n, int m) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j)
      printf("%d ", matrix[i][j]);
    printf("\n");
  }
}


int main(int argc, char *argv[]) {
  int a[][3] = { 1,2,3,
		 4,5,6,
		 7,8,9 } ;

  print_matrix1(a, 3, 3);

}
  
