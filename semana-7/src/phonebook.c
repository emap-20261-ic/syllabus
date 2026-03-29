#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAPACITY 100
#define STR_SIZE 100
#define LINE_MAX 300

typedef struct person {
  char name[STR_SIZE];
  char number[STR_SIZE];
} t_person;


void fixme(char *b) {
  b[strcspn(b, "\n")] = '\0';
}

void read(char *filename, t_person db[], int *n) {

  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error: invalid file.\n");
    exit(1);
  }

  char line[LINE_MAX];
  long int s = sizeof(line);
  while (fgets(line, s, file) != NULL) {
    t_person p;
    fixme(line);
    sscanf(line, "%[^,],%[^\n]", p.name, p.number);
    db[++(*n)] = p;
  }
  
  fclose(file);
}

void save(char *filename, t_person db[], int n) {

  FILE *file = fopen(filename, "w");
  if (file == NULL) {
    printf("Error: invalid file.\n");
    exit(1);
  }

  for(int i = 0; i <= n; i++) 
    fprintf(file, "%s,%s\n", db[i].name, db[i].number);
  
  fclose(file);
}

void list(t_person db[], int n) {
  for(int i = 0; i <= n; i++) 
    printf("%s\t%s\n", db[i].name, db[i].number);
  
}

void add(t_person db[], int *n) {

  t_person p;

  printf("Name: ");
  fgets(p.name, sizeof(p.name), stdin);
  fixme(p.name);

  printf("Phone: ");
  fgets(p.number, sizeof(p.number), stdin);
  fixme(p.number);

  db[++(*n)] = p;
}


void del(t_person db[], int *n) {
  char name[STR_SIZE];

  printf("Enter the name of the person to remove: ");
  fgets(name, sizeof(name), stdin);
  fixme(name);
  
  for (int i = 0; i <= *n; i++) {
    if (strcmp(db[i].name, name) == 0) {
      for (int j = i; j < *n; j++) 
	db[j] = db[j + 1];
      (*n)--;
      printf("Person %s removed successfully.\n", name);
      return;
    }
  }
  printf("Person %s not found in the database.\n", name);
}


int main(int argc, char *argv[]) {

  if(argc < 3) {
    printf("Usage: %s FILENAME {list|add}\n", argv[0]);
    return 1;
  }

  char *filename = argv[1];
  char *command = argv[2];
  t_person db[CAPACITY];
  int n = -1;

  if(strcmp(command,"list") == 0) {

    read(filename, db, &n);
    list(db, n);

  } else if(strcmp(command, "add") == 0) {

    read(filename, db, &n);
    add(db, &n) ;
    save(filename, db, n);
    list(db, n);

  } else if (strcmp(command, "remove") == 0) {
    
    read(filename, db, &n);
    del(db, &n);
    save(filename, db, n);
    list(db, n);

  }

  else {

    printf("Error: command Invalid\n");
    return 1;
    
  }

  return 0;
}

