#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// fila de inteiros

typedef struct node {
  int data;
  struct node *next;
} t_node;

typedef struct queue {
  t_node *front;
  t_node *rear;
} t_queue;


t_queue* create_queue();
t_node*  create_node(int k);

void enqueue(t_queue* q, int k);
void dequeue(t_queue* q);

int  q_front(t_queue *q);
int   q_rear(t_queue *q);
void q_print(t_queue *q);

