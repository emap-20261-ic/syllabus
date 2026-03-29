#include <stdio.h>
#include <string.h>

typedef char* string;

typedef struct {
  char name[50];
  int  idade;
  char telefone[50];
} person;

int main() {

  person a = { "Eduardo", 12, "+85 1234" };
  
  person b;
  b.idade = 10;

  // b.name = "..." will not work
  strcpy(b.name, "Beatriz"); 
 
  printf("Person: %s %d\n", b.name, b.idade);

}
