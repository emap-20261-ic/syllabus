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


int* list_array(t_node* head, int size) {
  int* arr = malloc(size * sizeof(int));
  t_node* t = head;
  int i = 0;
  while (t) {
    arr[i++] = t->number;
    t = t->next;
  }
  return arr;
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


void list_split(t_node *source, t_node **fref, t_node **bref) {
  t_node* fast;
  t_node* slow;
  slow = source;
  fast = source->next;
  
  // advance 'fast' two nodes, and advance 'slow' one node 
  while (fast != NULL) {
    fast = fast->next;
    if (fast != NULL) {
      slow = slow->next;
      fast = fast->next;
    }
  }
  
  // 'slow' is before the midpoint
  *fref = source;
  *bref = slow->next;
  slow->next = NULL;
}


t_node* merge_sorted(t_node *a, t_node *b) {
  t_node* result = NULL;

  // base case
  if (a == NULL)
    return b;
  else if (b == NULL)
    return a;
  
  if (a->number <= b->number) {
    result = a;
    result->next = merge_sorted(a->next, b);
  }
  else {
    result = b;
    result->next = merge_sorted(a, b->next);
  }
  return result;
}


/* sorts the linked list by changing next pointers (not data) */
void merge_sort(t_node **ref) {
  t_node *head = *ref;
   t_node *a;
  t_node *b;
  
  /* base case - length 0 or 1 */
  if ((head == NULL) || (head->next == NULL)) {
    return;
  }
  
  list_split(head, &a, &b);
  merge_sort(&a);
  merge_sort(&b);
  *ref = merge_sorted(a, b);
}


int list_hasloop(t_node* head) {
  t_node* slow = head;
  t_node* fast = head;

  while (fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
    
    if (slow == fast) {
      return 1;
    }
  }
  return 0;
}


void list_filter(t_node **head, int (*f) (int)) {
  t_node *curr = *head, *prev = NULL;
  while (curr != NULL) {
    if (!f(curr->number)) {
      if (prev != NULL) {
	prev->next = curr->next;
	free(curr);
	curr = prev->next;
      } else {
	*head = curr->next;
	free(curr);
	curr = *head;
      }
    } else {
      prev = curr;
      curr = curr->next;
    }
  }
}
