#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include <assert.h>

typedef struct node {
    int number;
    struct node *next;
} t_node;


int list_nth(t_node *list, int n) {
  int c = 0;
  for(t_node *t = list; t != NULL; t = t->next)
    if(c++ == n)
      return t->number;
  exit(1);
}

int list_first(t_node *list) {
  if(list == NULL)
    exit(1);
  else
    return list->number;
}

t_node* list_rest(t_node *list) {
  if(list == NULL)
    exit(1);
  else
    return list->next;
}

int list_size(t_node *list){
  int n = 0;
  for(t_node *t = list; t != NULL; t = t->next)
    n++;
  return n;
}

t_node* list_insert(int element, t_node* list) {
  t_node* n = malloc(sizeof(t_node));
  n->number = element;
  n->next = list;
  return n;
}

void list_print(t_node *list, char* sep) {
  for (t_node *tmp = list; tmp != NULL; tmp = tmp->next) 
    printf("%i%s", tmp->number, sep);
}

t_node* list_reverse(t_node *a) {
  t_node *new = NULL;
  for(t_node* tmp = a; tmp != NULL; tmp = tmp->next) {
    new = list_insert(tmp->number, new);
  }
  return new;
}


t_node* list_create(int arr[], int N) {
  t_node* head = NULL;
  
  for (int i = N - 1; i >= 0; i--) {
    head = list_insert(arr[i], head);
  }
  return head;
}


t_node* list_copy(t_node *head) {
  if (head == NULL) {
    return NULL;
  } else {
    t_node *new = malloc(sizeof(t_node));
    new->number = head->number;
    new->next = list_copy(head->next);
    return new;
  }
}
  
void list_nconc(t_node *a, t_node *b){
  if (a == NULL) a = b;
  t_node *tmp;
  for(tmp = a; tmp->next != NULL; tmp = tmp->next);
  tmp->next = b;
}


t_node* list_append(t_node *a, t_node *b){
  if (a == NULL) return b;
  t_node *tmp;
  t_node *new = list_copy(a);
  for(tmp = new; tmp->next != NULL; tmp = tmp->next);
  tmp->next = b;
  return new;
}


void list_del(t_node *a) {
  t_node* tmp;
  while (a != NULL) {
    tmp = a;
    a = a->next;
    free(tmp);
  }
}

void list_del_rec(t_node *a) {
  if(a == NULL) return ;
  list_del_rec(a->next);
  free(a);
}

