#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

// structure and functions

#define SIZE_OF_ALPHABET 26
#define MAXLEN 40

typedef struct node {
  int is_word;
  struct node *children[SIZE_OF_ALPHABET];
} node;


node* new_node   ();
void  add_word   (node* root, char *word);
int   get_idx    (char c);
char  idx_char   (int i);
bool  check      (node* root, char *word);
void  unload     (node *root);
void  statitics  (node *root, int* words);
void  print_trie (node *root, char *filename);


// uso da estrutura

int main(int argc, char *argv[]) {

    if (argc < 3) {
      printf("Usage: %s infile name1 name2 name3 ...\n", argv[0]);
      return 1;
    }

    FILE *infile = fopen(argv[1], "r");
    if (!infile) {
      printf("Error opening file!\n");
      return 1;
    }

    node* root = new_node();
    char  name[MAXLEN];
    int   longest = 0;
    
    while (fgets(name, 20, infile) != NULL) {

      // removing the end-line
      name[strcspn(name, "\n")] = '\0';
      // learn the longest name
      longest = strlen(name) > longest ? strlen(name) : longest; 

      add_word(root, name);
    }

    print_trie(root, "trie.dot");

    for(int i = 2; i < argc; i++)
      printf("%*s %s\n", longest, argv[i],
	     check(root, argv[i]) ? "Found!" : "Not Found.");

    int nwords = 0;
    statitics(root, &nwords);
    printf("number of words: %d\n", nwords);

    unload(root);
    fclose(infile);
}



// implementation of functions

void print_trie_node(node *cursor, FILE* stream) {
  if (cursor->is_word > 0)
    fprintf(stream, " a%p [label=\"%d\", style=filled, color=\"green\"];\n",
	    cursor, cursor->is_word);
  else
    fprintf(stream, " a%p [label=\"\"];\n", cursor);
  for (int i = 0; i < SIZE_OF_ALPHABET; i++)
    if (cursor->children[i] != NULL) {
      fprintf(stream, " a%p -> a%p [label=\"%c\"];\n",
	      cursor,
	      cursor->children[i],
	      idx_char(i));
      print_trie_node(cursor->children[i], stream);
    }
}


void print_trie(node *cursor, char* filename) {
  FILE *out;
  out = fopen(filename, "w");

  if (out == NULL) {
    printf("Unable to open the file.\n");
    exit(1);
  }

  fprintf(out, "digraph test {\n");
  print_trie_node(cursor, out);

  fprintf(out, "}\n");
  fclose(out);
  
}


void statitics(node* cursor, int *words) {

  if ( cursor == NULL )
    return ;

  *words += (cursor->is_word > 0 ? 1 : 0);  

  for (int i = 0; i < SIZE_OF_ALPHABET; i++)
    if (cursor->children[i] != NULL) {
      statitics(cursor->children[i], words);
    }
}


int get_idx(char c) {
  return tolower(c) - 'a';
}

char idx_char(int i) {
  return 'a' + i;
}


node* new_node() {
  node* tmp = malloc( sizeof(node) );
  assert( tmp != NULL );

  tmp->is_word = 0;
  for (int i = 0; i < SIZE_OF_ALPHABET; i++) 
    tmp->children[i] = NULL;

  return tmp;
}


void add_word(node* cursor, char *word) {
  
  for (int i = 0; word[i] != '\0'; i++) {
    int index = get_idx(word[i]);
    if (cursor->children[index] == NULL) {
      node *new = new_node();
      cursor->children[index] = new;
    }
    cursor = cursor->children[index];
  }
  cursor->is_word++;
}


bool check(node* cursor, char* word) {
  
  int  p = 0;
  
  while ( *(word + p) != '\0' && cursor) {
    char c = *(word + p++);
    int  i = get_idx(c);
    cursor = cursor->children[i];
  }
  if(cursor != NULL && cursor->is_word > 0)
    return true;
      
  return false;
}


void unload(node* current) {
  
  for (int i = 0; i < SIZE_OF_ALPHABET; i++) 
    if (current->children[i] != NULL) 
      unload(current->children[i]);
  free(current);
}


/*

  % gcc trie.c
  % ./a.out animais.txt bert thor miami flour Spencer
        bert Not Found.
        thor Not Found.
       miami Not Found.
       flour Not Found.
     Spencer Not Found.

*/     
