#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int number;
  struct node *next;
} t_node;


int pop(t_node **p) {
  assert(*p != NULL);
  int r = (*p)->number;
  t_node *t = *p;
  *p = (*p)->next;
  free(t);
  return r;
}

int peek(t_node *p) {
  assert(p != NULL);
  return p->number;
}

void push(t_node **p, int e) {
  t_node* n = malloc(sizeof(t_node));
  assert(n != NULL);
  n->number = e;
  n->next = *p;
  *p = n;
}


void stack_print(t_node *s) {
  for (t_node *t = s; t != NULL; t = t->next) 
    printf("%i ", t->number);
  printf("\n");
}


int main(int argc, char *argv[]) {

  t_node *s = NULL;

  push(&s, 1); 
  push(&s, 2); 
  push(&s, 3); 
  stack_print(s);

  printf("top is %d \n", peek(s));
  printf("popped %d \n", pop(&s));
  printf("top is %d \n", peek(s));
  stack_print(s);
	  
}
  

