#include <stdlib.h>
#include <stdio.h>

typedef char* string;

/* this function returns a negative number if `x` is not in `a`. */
int binary_search(int a[], int n, int x) {
  int low = 0, high = n - 1;
  while (low <= high) {
    int k = (high + low) / 2;
    if (a[k] == x)
      return k;
    else
      if (a[k] <  x)
	low  = k + 1;
      else
	high = k - 1;
  }
  return -1;
}

int main(int argc, string argv[]) {
  
  if (argc != 4) {
    fprintf(stderr, "Usage: %s NUMERO LINHAS ARQUIVO\n", argv[0]);
    return 1;
  }

  int q = atoi(argv[1]);
  int n = atoi(argv[2]);
  string filename = argv[3];

  if(n <= 0){
    fprintf(stderr, "LINHAS need to be greater than zero.\n");
    return 1;
  }    
  
  int a[n];

  // open the file
  FILE *f = fopen(filename, "r");
  if (!f) {
    fprintf(stderr, "Erro: nao foi possivel abrir '%s'.\n", filename);
    return 1;
  }

  // reading the numbers
  for (int i = 0; i < n; i++) {
    if (fscanf(f, "%d", &a[i]) != 1) {
      fprintf(stderr, "Erro: falha ao ler linha %d do arquivo.\n", i + 1);
      fclose(f);
      return 1;
    }
  }
  fclose(f);

  // search
  int idx = binary_search(a, n, q);

  // report to user the result
  if (idx >= 0) {
    printf("%d is at index %d.\n", q, idx);
    return 0;
  } else {
    printf("%d is not found.\n", q);
    return 2;
  }
}
