#include <stdio.h>
#include <glib.h>

int main(int argc, char** argv) {

  GList* list0 = NULL;
  list0 = g_list_append(list0, "Pedro");
  list0 = g_list_append(list0, "Mario");
  list0 = g_list_append(list0, "Roberto");
  list0 = g_list_append(list0, "Alexandre");

  for (GList *l = list0; l != NULL; l = l->next) 
    g_print("The item is '%s'\n", (char *) l->data );

  GList* list1 = NULL;
  list1 = g_list_append(list1, GINT_TO_POINTER(1) );
  list1 = g_list_append(list1, GINT_TO_POINTER(2) );
  list1 = g_list_append(list1, GINT_TO_POINTER(3) );
  list1 = g_list_append(list1, GINT_TO_POINTER(4) );
  
  for (GList *l = list1; l != NULL; l = l->next) 
    g_print("The item is '%d'\n", GPOINTER_TO_INT(l->data) );
  
  return 0;
}

/*

  On the MacOS, I needed 'clang' and 'pkg-config' from Homebrew
  
  $ pkg-config glib-2.0 --cflags --libs

  The command above gives me the flags I need to pass to clang

  $ clang `pkg-config glib-2.0 --cflags --libs` -o list list-glib.c

*/
