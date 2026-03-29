#include <stdio.h>
#include <stdlib.h>
#include "list.h"


int is_odd(int n){
  if(n % 2 == 0)
    return 0;
  else
    return 1;
}


int main(int argc, char *argv[]) {

  if (argc > 1) {
    FILE *fp;
    char line[100];
    t_node *c = NULL;

    fp = fopen(argv[1], "r");

    if (fp == NULL) {
      printf("Could not open file.\n");
      return 1;
    }

    while (fgets(line, sizeof(line), fp) != NULL) {
      c = list_insert(atoi(line), c);
      // c = list_append(c, list_insert(atoi(line), NULL));
    }

    merge_sort(&c);
    list_print(c, "\n");
    
  } else {
    
    t_node *a = list_insert(1, list_insert(2, list_insert(3, NULL)));
    int t1[] = {8, 7, 2, 1, 5, 3};
    t_node *b = list_create(t1, 6);

    t_node *r = NULL;
    t_node *s = NULL;
    t_node *t = NULL;

    printf("lists a and b\n");
    list_print(a, " "); printf("\n");
    list_print(b, " "); printf("\n");

    printf("copy list b and sort it\n");
    t = list_copy(b);
    merge_sort(&t); list_print(t, " "); printf("\n");
    
    printf("reverse a\n");
    list_print(list_reverse(a), " "); printf("\n");

    r = list_append(a, b);
    s = list_append(a, a);        
    printf("append(a,b)\n");    
    list_print(r, " "); printf("\n");
    printf("append(a,a)\n");    
    list_print(s, " "); printf("\n");
    
    printf("nconc(a,b) using temp\n");
    t = list_copy(a);
    list_nconc(t, b);
    list_print(t, " "); printf("\n");

    // make cycle and detect it
    t = list_copy(a); list_nconc(t, t);
    printf("nconc(a,a) has cycle: %d\n", list_hasloop(t));
    t = list_copy(a); list_nconc(t, b);
    printf("nconc(a,b) has cycle: %d\n", list_hasloop(t));
    
    printf("test size and nth \n");
    printf("a[%d] = %d \n", 2, list_nth(a, 2));
    printf("b size is %d \n", list_size(b));

    printf("filter b (odd numbers)\n");
    t = list_copy(b); list_filter(&t, is_odd);
    list_print(t, " "); printf("\n");

    printf("lists a and b\n");
    list_print(a, " "); printf("\n");
    list_print(b, " "); printf("\n");

    printf("lists b to array\n");
    int *t2 = list_array(b, 6);
    for(int i = 0; i < 6; i++)
      printf("%d ", t2[i]);
    printf("\n");
    
  }

  return 0;
}
