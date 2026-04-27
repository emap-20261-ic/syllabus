#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MENU_ITEMS 200
#define MAX_NAME_SIZE  100
#define MAX_LINE_SIZE  150

typedef char* string;

typedef struct {
  char  name[MAX_NAME_SIZE];
  float price;
} item;

typedef enum {
  CMD_PRINT_MENU,
  CMD_TOTAL,
  CMD_UNKNOWN
} command;

typedef enum {
  EXIT_OK          = 0, // success
  EXIT_OPEN        = 1, // could not open menu file
  EXIT_ITEM_COUNT  = 2, // could not read or parse item count
  EXIT_TOO_MANY    = 3, // menu exceeds max_items
  EXIT_ITEM_FORMAT = 4, // item line missing or has invalid format
  EXIT_UNKNOWN_CMD = 5  // unknown command or wrong usage
} exit_code;


void    to_lower_case(string s);
item*   find_item(item items[], int size, string name);
int     read_menu(FILE *fp, item items[], int max_items);
float   read_order(FILE *fp, item items[], int size, int *found);
command parse_command(string s);


int main(int argc, char *argv[]) {

  if (argc < 3) {
    fprintf(stderr, "Usage: %s <menu> print-menu\n", argv[0]);
    fprintf(stderr, "       %s <menu> total <pedido1> ...\n", argv[0]);
    return EXIT_UNKNOWN_CMD;
  }

  // read the menu
  FILE *menu_fp = fopen(argv[1], "r");
  if (menu_fp == NULL) {
    fprintf(stderr, "Error: cannot open menu file '%s'\n", argv[1]);
    return EXIT_OPEN;
  }
  item menu[MAX_MENU_ITEMS];
  int num_items = read_menu(menu_fp, menu, MAX_MENU_ITEMS);
  fclose(menu_fp);

  // process command
  switch (parse_command(argv[2])) {
    case CMD_PRINT_MENU:
      printf("Read %d items from the menu:\n", num_items);
      for (int i = 0; i < num_items; i++)
        printf("%20s: %5.2f\n", menu[i].name, menu[i].price);
      break;

    case CMD_TOTAL:
      for (int i = 3; i < argc; i++) {
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL) {
          fprintf(stderr, "Error: cannot open order file '%s'\n", argv[i]);
          continue;
        }
        int found = 0;
        float total = read_order(fp, menu, num_items, &found);
        fclose(fp);
        printf("file: %s found %3d items, total $%.2f\n", argv[i], found, total);
      }
      break;

    case CMD_UNKNOWN:
      fprintf(stderr, "Unknown command: %s\n", argv[2]);
      return EXIT_UNKNOWN_CMD;
  }
  return EXIT_OK;
}


command parse_command(string s) {
  if (strcmp(s, "print-menu") == 0) return CMD_PRINT_MENU;
  if (strcmp(s, "total")      == 0) return CMD_TOTAL;
  return CMD_UNKNOWN;
}


void to_lower_case(string s) {
  for (int i = 0; s[i] != '\0'; i++)
    s[i] = tolower(s[i]);
}


int read_menu(FILE *fp, item items[], int max_items) {
  char line[MAX_LINE_SIZE];
  int num_items = 0;

  if (fgets(line, sizeof(line), fp) == NULL || sscanf(line, "%d", &num_items) != 1) {
    fprintf(stderr, "Error: could not read item count from menu.\n");
    exit(EXIT_ITEM_COUNT);
  }

  if (num_items > max_items) {
    fprintf(stderr, "Error: menu has %d items, max is %d.\n", num_items, max_items);
    exit(EXIT_TOO_MANY);
  }

  for (int i = 0; i < num_items; i++) {
    if (fgets(line, sizeof(line), fp) == NULL) {
      fprintf(stderr, "Error: expected %d items but file ended at item %d.\n", num_items, i + 1);
      exit(EXIT_ITEM_FORMAT);
    }
    char name[MAX_NAME_SIZE];
    float price;
    if (sscanf(line, "%49[^:]:%f", name, &price) != 2) {
      fprintf(stderr, "Error: invalid format for item %d in menu.\n", i + 1);
      exit(EXIT_ITEM_FORMAT);
    }
    to_lower_case(name);
    strncpy(items[i].name, name, sizeof(items[i].name));
    items[i].price = price;
  }

  return num_items;
}


item* find_item(item items[], int size, string name) {
  for (int i = 0; i < size; i++) {
    if (strcmp(name, items[i].name) == 0)
      return &items[i];
  }
  return NULL;
}


float read_order(FILE *fp, item items[], int size, int *found) {
  char line[MAX_LINE_SIZE];
  float total = 0.0;
  *found = 0;
  while (fgets(line, sizeof(line), fp) != NULL) {
    line[strcspn(line, "\n")] = '\0';
    if (strcmp(line, "END") == 0) break;
    to_lower_case(line);

    item *it = find_item(items, size, line);
    if (it != NULL) {
      total += it->price;
      (*found)++;
    } else {
      fprintf(stderr, "warning: '%s' not found in menu\n", line);
    }
  }
  return total;
}
