#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// maximum size of the stack
#define MAX_SIZE 100 

typedef struct stack {
  int stack[MAX_SIZE];
  int top; 
} t_stack;


t_stack* make_stack(){
  t_stack *t = malloc(sizeof(t_stack));
  t->top = -1;
  return t;
}

void push(t_stack *s, int data) {
  assert(s->top < MAX_SIZE - 1);
  s->stack[++s->top] = data;
}

int pop(t_stack *s) {
  assert(s->top > -1);
  return s->stack[s->top--];
}

int peek(t_stack *s) {
  assert(s->top > -1);
  return s->stack[s->top];
}

int is_empty(t_stack *s) {
  return (s->top == -1);
}

void stack_print(t_stack *s) {
  for(int i = s->top ; i >= 0 ; i--) {
    printf("%d ", s->stack[i]);
  }
  printf("\n");
}


int main(int argc, char* argv[]) {

  t_stack *s = make_stack();

  push(s, 1);
  push(s, 2);
  push(s, 3);

  stack_print(s);
  printf("popped %d \n", pop(s));
  stack_print(s);

}
