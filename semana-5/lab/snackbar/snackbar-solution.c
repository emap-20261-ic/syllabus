#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

typedef char* string;

// menu items have item name and price
typedef struct
{
  char name[50];
  float price;
}
item;


void to_lower_case(string str) {
  for (int i = 0; str[i] != '\0'; i++) 
    str[i] = tolower(str[i]);
}


int read_items_from_file_1(string filename, item items[], int max_items){
  
  int num_items = 0;
  
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Error: cannot open file.\n");
      exit(1);
  }
  
  // read number of items from first line of file
  if (fscanf(fp, "%d\n", &num_items) != 1) {
    printf("Error: invalid file format.\n");
    exit(1);
  }
  
  if (num_items > max_items) {
    printf("Error: too many items in file.\n");
    exit(1);
  }
  
  char line[100];
  int count = 0;
  while (fgets(line, sizeof(line), fp) != NULL) {
    string token = strtok(line, ":");
    if (token != NULL) {
      strcpy(items[count].name, token);
    }
    token = strtok(NULL, "\n");
    if (token != NULL) {
      items[count].price = atof(token);
    }
    count++;
  }
  
  fclose(fp);
  return count;
}

int read_items_from_file(string filename, item items[], int max_items) {
    int num_items = 0;

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
      printf("Error: cannot open file.\n");
      exit(1);
    }

    // read number of items from first line of file
    if (fscanf(fp, "%d\n", &num_items) != 1) {
      printf("Error: invalid file format.\n");
      exit(1);
    }

    if (num_items > max_items) {
      printf("Error: too many items in file.\n");
      exit(1);
    }

    // read items from file
    for (int i = 0; i < num_items; i++) {
      char name[50];
      float price;

      // See https://man7.org/linux/man-pages/man3/scanf.3.html 
      if (fscanf(fp, "%[^:]:%f\n", name, &price) == 2) {

	// convert string to lowercase
	to_lower_case(name);
	
	strncpy(items[i].name, name, sizeof(items[i].name));
	items[i].price = price;
      }
      else {
	printf("Error: invalid file format.\n");
	exit(1);
      }
    }

    fclose(fp);
    return num_items;
}



float get_total(item menu[], int size) {

    char line[100];
    float total = 0.0;
    while (fgets(line, sizeof(line), stdin) != NULL) {

      // remove newline character
      line[strcspn(line, "\n")] = '\0';
      
      // Check for END line
      if (strcmp(line, "END") == 0) {
	break;
      }

      // convert string to lowercase
      to_lower_case(line);

      // search for the line in menu
      for (int i = 0; i < size; i++) {
	if (strcmp(line, menu[i].name) == 0) {
	  total += menu[i].price;
	  break;
	}
      }
    }
    return total;
}


int main(void) {

  const int MAX_ITEMS = 100;
  item menu[MAX_ITEMS];

  int num_items = read_items_from_file("menu.txt", menu, MAX_ITEMS);

  // print all items read from the menu
  printf("Read %d items from the menu:\n", num_items);
  for (int i = 0; i < num_items; i++) {
    // this alignment of the output assumes that menu only contains
    // names of products with less than 20 chars.
    printf("- %-20s: %.2f\n", menu[i].name, menu[i].price);
  }

  float total = get_total(menu, num_items);
  printf("\n>> total cost: $%.2f\n", total);
}

