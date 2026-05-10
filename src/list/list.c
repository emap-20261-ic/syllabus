/*
  some ideas from
  https://www.geeksforgeeks.org/c-program-to-create-copy-of-a-singly-linked-list-using-recursion/
*/  

#include <stdio.h>
#include <stdlib.h>
#include "list.h"


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

void list_print(t_node *list) {
  for (t_node *tmp = list; tmp != NULL; tmp = tmp->next) 
    printf("%i ", tmp->number);
  printf("\n");
}


t_node* list_reverse(t_node *head) {
  t_node *new = NULL;
  for(t_node* tmp = head; tmp != NULL; tmp = tmp->next) {
    new = list_insert(tmp->number, new);
  }
  return new;
}

t_node* list_reverse_rec(t_node* head) {

  // base case: if list is empty or there's only one node
  if (head == NULL || head->next == NULL) 
    return head;

  // recursively reverse the rest of the list.
  t_node* new_head = list_reverse_rec(head->next);

  // reverse the pointer of the current node's next element
  head->next->next = head;
  // ensure that head becomes the tail 
  head->next = NULL;

  return new_head;
}

t_node* list_nreverse1(t_node *head) {
  t_node *prev = NULL;
  t_node *current = head;
  t_node *next = NULL;

  while (current != NULL) {
    next = current->next; // save next
    current->next = prev; // reverse pointer
    
    // move pointers one step forward
    prev = current;
    current = next;
  }
  return prev;
}


void list_nreverse2(t_node **head) {
  t_node *prev = NULL;
  t_node *current = *head;
  t_node *next = NULL;

  while (current != NULL) {
    next = current->next;  // save next
    current->next = prev;  // reverse pointer
    
    // move pointers one step forward
    prev = current; 
    current = next;
  }
  *head = prev;
}


t_node* list_create(int arr[], int n) {
  t_node* list = NULL;
  
  for (int i = n - 1; i >= 0; i--) {
    list = list_insert(arr[i], list);
  }
  return list;
}


t_node* list_copy(t_node *list) {
  if (list == NULL) {
    return NULL;
  } else {
    t_node *new = malloc(sizeof(t_node));
    new->number = list->number;
    new->next = list_copy(list->next);
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
  t_node *new = list_copy(a);
  list_nconc(new, b);
  return new;
}


void list_del(t_node *list) {
  t_node* tmp;
  while (list != NULL) {
    tmp = list;
    list = list->next;
    free(tmp);
  }
}

void list_del_rec(t_node *list) {
  if(list == NULL) return ;
  list_del_rec(list->next);
  free(list);
}


int list_foldr(t_node *head, int (*f)(int, int), int e) {
  if (head == NULL)
    return e;
  return f(head->number, list_foldr(head->next, f, e));
}


int list_foldl(t_node *head, int (*f)(int, int), int e) {
  if (head == NULL)
    return e;
  return list_foldl(head->next, f, f(head->number, e));
}

