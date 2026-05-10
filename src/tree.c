#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <glib.h>

// the tree

typedef struct node  {
  int key;
  struct node *left, *right;
} t_node;


t_node* new_node(int item) {
  t_node* t = malloc(sizeof(struct node));
  assert(t != NULL);
  t->key = item;
  t->left = t->right = NULL;
  return t;
}


t_node* insert(t_node* node, int key) {
  if (node == NULL)
    return new_node(key);

  if (key < node->key)
    node->left = insert(node->left, key);
  else if (key > node->key)
    node->right = insert(node->right, key);

  return node;
}


int height(t_node* node) {
  if(node == NULL)
    return 0;

  int left  = height(node->left);
  int right = height(node->right);

  return (left >= right ? left : right) + 1;
  
}

void free_tree(t_node *root) {
    if (root == NULL)
      return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}


bool binary_search(t_node *root, int n) {
  if (root == NULL)
    return false;
  else if (n < root->key)
    return binary_search(root->left, n);
  else if (n > root->key)
    return binary_search(root->right, n);
  return (n == root->key);
}



// QUEUE for BFS on the tree using ARRAY

#define MAX_QUEUE_SIZE 100

typedef struct {
  t_node* items[MAX_QUEUE_SIZE];
  int front, rear;
} t_queue;


t_queue* create_queue() {
    t_queue* queue = malloc(sizeof(t_queue));
    assert(queue != NULL);
    queue->front = queue->rear = -1;
    return queue;
}

int queue_is_empty(t_queue* queue) {
    return (queue->front == -1 && queue->rear == -1);
}

int queue_is_full(t_queue* queue) {
  return ((queue->rear + 1) % MAX_QUEUE_SIZE == queue->front);
}

void enqueue(t_queue* queue, t_node* n) {
    if (queue_is_full(queue)) {
      printf("Queue is full\n");
      return;
    }

    if (queue_is_empty(queue))
        queue->front = queue->rear = 0;
    else
        queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;

    queue->items[queue->rear] = n;
}

t_node* dequeue(t_queue* queue) {
    t_node* value;
    if (queue_is_empty(queue)) {
        printf("Queue is empty\n");
        return NULL;
    }

    value = queue->items[queue->front];

    if (queue->front == queue->rear)
      queue->front = queue->rear = -1;
    else
      queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;

    return value;
}


// traversing the tree

void inorder(t_node* root) {
  if (root != NULL) {
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
  }
}

void posorder(t_node* root) {
  if (root != NULL) {
    posorder(root->left);
    posorder(root->right);
    printf("%d ", root->key);
  }
}

void preorder(t_node* root) {
  if (root != NULL) {
    printf("%d ", root->key);
    preorder(root->left);
    preorder(root->right);
  }
}


void bfs0(t_node* root) {

  if(root == NULL)
    return;
  
  t_queue *q = create_queue();
  enqueue(q, root);
  
  while( ! queue_is_empty(q) ) {
    t_node* n = dequeue(q);
    if(n->left != NULL)  enqueue(q, n->left);
    if(n->right != NULL) enqueue(q, n->right);
    printf("%d ", n->key);
  }
  assert( queue_is_empty(q) );
  free(q);
}

void bfs1(t_node* root){

  // https://docs.gtk.org/glib/data-structures.html#double-ended-queues

  GQueue* q = g_queue_new();

  if(root == NULL)
    return;
  
  g_queue_push_tail(q, root);
  
  while( ! g_queue_is_empty(q) ) {
    t_node* n = (t_node*) g_queue_pop_head(q);
    if(n->left != NULL)  g_queue_push_tail(q, n->left);
    if(n->right != NULL) g_queue_push_tail(q, n->right);
    printf("%d ", n->key);
  }
  g_queue_free(q);
}



void test1() {
  
  // testing tree traversals

    /*
              1
            /   \
           2     3
          /  \   /  
         4    5 6   
    */
  t_node* r = new_node(1);
  r->left  = new_node(2);
  r->right = new_node(3);
  r->left->left  = new_node(4);
  r->left->right = new_node(5);
  r->right->left = new_node(6);
    
  printf(" inorder:\n"); inorder(r);  printf("\n");
  printf("preorder:\n"); preorder(r); printf("\n");
  printf("posorder:\n"); posorder(r); printf("\n");
  printf("bfs0:\n"); bfs0(r); printf("\n");
  printf("bfs1:\n"); bfs1(r); printf("\n");

}


int main(int argc, char* argv[]) {


  if(argc < 3) {
    test1();
    return 0;
  }

  // testing binary search  

  FILE *file = NULL;

  file = fopen(argv[1], "r");
  if (file == NULL) {
    printf("Error opening %s!\n", argv[1]);
    return EXIT_FAILURE;
  }

  t_node* root = NULL;
  int tmp;

  while (fscanf(file, "%d", &tmp) != EOF) {
    root = insert(root, tmp);
  }

  printf("The tree has height %d\n", height(root));

  int target = atoi(argv[2]);
  
  printf("search %i is %i\n",
	 target,
	 binary_search(root, target));


  fclose(file);
  return EXIT_SUCCESS;
}
  

/*

  clang `pkg-config glib-2.0 --cflags --libs` tree.c

  % ./a.out
  inorder:
  4 2 5 1 6 3
  preorder:
  1 2 4 5 3 6
  posorder:
  4 5 2 6 3 1
  bfs0:
  1 2 3 4 5 6
  bfs1:
  1 2 3 4 5 6

  % time ./a.out ../../semana-5/exercicios/sort/reversed50000.txt 45
  The tree has height 50000
  search 45 is 1
  ./a.out ../../semana-5/exercicios/sort/reversed50000.txt 45
  10.09s user 0.01s system 99% cpu 10.141 total

  % time ./a.out ../../semana-5/exercicios/sort/random50000.txt 45
  The tree has height 40
  search 45 is 1
  ./a.out ../../semana-5/exercicios/sort/random50000.txt 45
  0.03s user 0.01s system 62% cpu 0.059 total
  
*/
