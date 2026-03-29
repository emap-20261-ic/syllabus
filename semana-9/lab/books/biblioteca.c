#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <list.h>

typedef struct Livro {
    char titulo[100];
    char autor[50];
    int isbn; 
} Livro;



Livro *biblioteca = NULL; 

void cadastrarLivro();
void buscarLivro();
void removerLivro();
void listarLivros();
void salvarEmArquivo();
void carregarDeArquivo();
void liberarMemoria();

// Menu interativo
void exibirMenu() {
    printf("\n=== BIBLIOTECA ===\n");
    printf("1. Cadastrar livro\n");
    printf("2. Buscar livro\n");
    printf("3. Remover livro\n");
    printf("4. Listar todos os livros\n");
    printf("5. Salvar dados\n");
    printf("6. Carregar dados\n");
    printf("7. Sair\n");
    printf("==================\n");
    printf("Escolha uma opção: ");
}

int main() {
    int opcao;
    do {
        exibirMenu();
        scanf("%d", &opcao);
        getchar();

        switch(opcao) {
            case 1: cadastrarLivro(); break;
            case 2: buscarLivro(); break;
            case 3: removerLivro(); break;
            case 4: listarLivros(); break;
            case 5: salvarEmArquivo(); break;
            case 6: carregarDeArquivo(); break;
            case 7: liberarMemoria(); break;
            default: printf("Opção inválida!\n");
        }
    } while (opcao != 7);

    return 0;
}

void cadastrarLivro() {
    Livro *n = malloc(sizeof(Livro));
    if (n == NULL) {
        printf("Erro ao alocar memória!\n");
        return;
    }

    printf("Título: ");
    fgets(n->titulo, 100, stdin);

    int i = 0;
    while(n->titulo[i] != '\0'){
        n->titulo[i] = tolower(n->titulo[i]);
        i++;
    }

    printf("Autor: ");
    fgets(n->autor, 50, stdin);
    n->autor[strcspn(n->autor, "\n")] = '\0';

    n->titulo[strcspn(n->titulo, "\n")] = '\0';

    printf("ISBN: ");
    scanf("%d", &n->isbn);

    n->prox = NULL;

    if (biblioteca == NULL) {
        biblioteca = n;
    } 
    else {
        Livro *atual = biblioteca;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = n;
    }
    printf("Novo livro cadrastado com sucesso!\n");
}


char* toLower(char *txt) {
  /** int i = 0;
  while(temp[i] != '\0'){
    temp[i] = tolower(temp[i]);
    i++;
    } **/
}

void printLivro(Livro *b) {
  // print as partes do livro
}


Livro* buscaLivro(node *biblioteca, char* title) {
  // loop buscando livro
  // return ponteiro para o livro ou NULL
  /*

        Livro *current = biblioteca;
    while(current != NULL){
        char tituloTemp[100];
        strcpy(tituloTemp, current->titulo);

        if(strcmp(temp, tituloTemp) == 0)
	  printLivro(current);
        current = current->prox;
    }
  */
}  


void buscarLivro(){
   
    if(biblioteca == NULL) {
        printf("A biblioteca está vazia\n");
        return;
    }

    // pergunta qual livro
    char temp[100];
    printf("Digite o título: ");
    fgets(temp, 100, stdin);
    temp[strcspn(temp, "\n")] = '\0';
    toLower(temp);

    // busca
    Livro *l = buscaLivro(bib, temp);
    
    printf("Livro não encontrado.\n");
}


void removerLivro() {
    
    if(biblioteca == NULL) {
        printf("A biblioteca está vazia\n");
        return;
    }

    char temp[100];
    printf("Nome do Livro para remover: ");
    fgets(temp, 100, stdin);
    temp[strcspn(temp, "\n")] = '\0';

   char answer;
    do {
    printf("Deseja mesmo remover este livro? Será perdido para sempre. [S/N]: ");
    scanf(" %c", &answer);
    while (getchar() != '\n');
    answer = toupper(answer);
    } while (answer != 'S' && answer != 'N');
   
    Livro *current = biblioteca;
    Livro *prev = NULL;
    int removed = 0;

    if(answer == 'S') {
        int i = 0;
        while(temp[i] != '\0'){
            temp[i] = tolower(temp[i]);
            i++;
        }

        while(current != NULL){
            if(strcmp(temp, current->titulo) == 0) {
                if(prev == NULL) {
                    biblioteca = current->prox;
                } else{
                    prev->prox = current->prox;
                }
                Livro *prox = current->prox;
                free(current);
                current = prox;
                removed = 1;
                continue;
            }
            prev = current;
            current = current->prox;
        }
    }
    if(removed){
        printf("Livro removido com sucesso!\n");
    }
    if(!removed){
        printf("Livro não encontrado!\n");
    }
}

void listarLivros(){
    if(biblioteca == NULL) {
        printf("A biblioteca está vazia\n");
        return;
    }

    Livro *current = biblioteca;

    while(current != NULL){
        printf("[ISBN: %d] \"%s\" - %s\n", current->isbn, current->titulo, current->autor);
        current = current->prox;
    }
}

void salvarEmArquivo() {

    FILE *arquivo = fopen("Biblioteca.txt", "w");
    if(arquivo == NULL) {
        printf("Erro ao criar o arquivo\n");
        return;
    }

    Livro *current = biblioteca;
    while(current != NULL) {
        fprintf(arquivo, "[ISBN: %d] \"%s\" - %s\n", current->isbn, current->titulo, current->autor);
        current = current->prox;
    }
    fclose(arquivo);
    printf("Dados salvos com sucesso!\n");
}

void carregarDeArquivo() {
    FILE *arquivo = fopen("Biblioteca.txt", "r");
    if (arquivo == NULL) {
        printf("Arquivo não encontrado ou erro ao abrir\n");
        return;
    }

    char answer;
    do {
    printf("Deseja mesmo carregar? Dados não salvos serão perdidos. [S/N]: ");
    scanf(" %c", &answer);
    while (getchar() != '\n');
    answer = toupper(answer);
    } while (answer != 'S' && answer != 'N');

    int loaded = 0;

    //Está limpando a biblioteca, aproveitando espaço (vantagem e desvantagem)
   if(answer == 'S') {
        Livro *current = biblioteca;
        while (current != NULL) {
            Livro *temp = current;
            current = current->prox;
            free(temp);
        }
        biblioteca = NULL;

        char linha[256];
        while (fgets(linha, sizeof(linha), arquivo) != NULL) {
            int isbn;
            char titulo[100], autor[50];
            
            if (sscanf(linha, "[ISBN: %d] \"%99[^\"]\" - %49[^\n]", &isbn, titulo, autor) == 3) {
                
                Livro *n = malloc(sizeof(Livro));
                if (n == NULL) {
                    printf("Erro de alocação de memória\n");
                    continue;
                }

                strncpy(n->titulo, titulo, sizeof(n->titulo) - 1);
                n->titulo[sizeof(n->titulo) - 1] = '\0';
                
                strncpy(n->autor, autor, sizeof(n->autor) - 1);
                n->autor[sizeof(n->autor) - 1] = '\0';
                
                n->isbn = isbn;
                n->prox = NULL;

                if (biblioteca == NULL) {
                    biblioteca = n;
                } else {
                    Livro *last = biblioteca;
                    while (last->prox != NULL) {
                        last = last->prox;
                    }
                    last->prox = n;
                    loaded = 1;
                }
            }
        }
    } else {
        printf("Operação cancelada!");
    }
    fclose(arquivo);
    if(loaded) {
        printf("Dados carregados com sucesso!\n");
    }
    if(!loaded) {
        printf("Não há dados para serem carregados\n");
    }
}

void liberarMemoria() {

    if(biblioteca == NULL) {
        printf("Biblioteca vazia, encerrando programa...\n");
        exit(EXIT_SUCCESS);
    }

    char answer;
    do {
    printf("Deseja mesmo sair? Dados não salvos serão perdidos. [S/N]: ");
    scanf(" %c", &answer);
    while (getchar() != '\n');
    answer = toupper(answer);
    } while (answer != 'S' && answer != 'N');
   
    if(answer == 'S') {
        Livro *current = biblioteca;
        
        while(current != NULL) {
            Livro *prox = current->prox;
            free(current);
            current = prox;
        }
         biblioteca = NULL;
        printf("Memória liberada, encerrando programa...\n");
        exit(EXIT_SUCCESS);
    } else{
        printf("Operação cancelada\n");
        return;
    }
}
