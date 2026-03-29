#include <stdio.h>
#include <ctype.h>

int main() {
  
    FILE *arquivo = fopen("entrada.txt", "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    char palavra[1024]; 
    int i = 0;
    int c;

    while ((c = fgetc(arquivo)) != EOF) {
        if (isspace(c)) {
	  // acabei de ler um palavra
	  if (i > 0) { // só imprime se houver algo no buffer
	    palavra[i] = '\0'; // finaliza a string
	    printf("Palavra: %s\n", palavra);
	    i = 0; // reinicia o índice para a próxima palavra
	  }
        } else {
	  // lendo uma palavra
	  palavra[i++] = c;
        }
    }

    // Se o arquivo não terminar com um espaço, imprime a última palavra
    if (i > 0) {
        palavra[i] = '\0';
        printf("Palavra: %s\n", palavra);
    }

    fclose(arquivo);
    return 0;
}

