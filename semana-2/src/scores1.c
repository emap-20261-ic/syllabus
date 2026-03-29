#include <stdio.h>

int main(void) {

    int n = 0;
    printf("Quantos valores? ");
    scanf("%d", &n);

    if( n <= 0) { 
        return 1;
    }
  
    int scores[n];
    float soma = 0;

    for(int i = 0; i < n; i++) {
        printf("valor[%i]: ", i);
        scanf("%d", &scores[i]);
        soma = soma + scores[i];
    }
    
    printf("Average: %f\n", soma / (float) n);
}
