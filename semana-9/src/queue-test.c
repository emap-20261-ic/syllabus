#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


void fun(int n) {

  t_queue *q = create_queue();
  enqueue(q, 0);
  enqueue(q, 1);
  
  for (int i = 0; i < n; i++) {
    int a = q_front(q); dequeue(q);
    int b = q_front(q); dequeue(q);
    enqueue(q, b);
    enqueue(q, a + b);
    printf("%d ", a);
  }
}


int main(int argc, char *argv[]) {

  fun(10);
  
}
  
// gcc queue.c queue-test.c

