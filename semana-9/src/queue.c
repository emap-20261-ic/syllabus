#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


t_node* create_node(int k) {
  t_node* temp = malloc(sizeof(t_node));
  temp->data = k;
  temp->next = NULL;
  return temp;
}

t_queue* create_queue() {
    t_queue *q = malloc(sizeof(t_queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(t_queue* q, int k) {
  t_node* temp = create_node(k);

  // if empty
  if (q->rear == NULL) {
    q->front = q->rear = temp;
    return;
  }
 
  q->rear->next = temp;
  q->rear = temp;
}

void dequeue(t_queue* q) {

  // if empty
  if (q->front == NULL)
    return;
 
  // store previous front and move front one node ahead
  t_node* temp = q->front;
  q->front = q->front->next;
 
  // if front becomes NULL, then change rear also as NULL
  if (q->front == NULL)
    q->rear = NULL;

  free(temp);
}

int q_front(t_queue *q) {
  assert(q != NULL && q->front != NULL);
  return q->front->data;
}

int q_rear(t_queue *q) {
  assert(q != NULL && q->rear != NULL);
  return q->rear->data;
}

void q_print(t_queue *q) {
  for (t_node *t = q->front; t != NULL; t = t->next) 
    printf("%i ", t->data);
  printf("\n");
}


