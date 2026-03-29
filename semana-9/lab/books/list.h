
typedef struct node t_node;

void*   list_nth(t_node *list, int n);
void*   list_first(t_node *list);
int     list_size(t_node *list);

t_node* list_rest(t_node *list);
t_node* list_insert(void* data, t_node* list);

t_node* list_reverse(t_node *list);
t_node* list_reverse_rec(t_node *list);
t_node* list_nreverse1(t_node *list);
void    list_nreverse2(t_node **list);

t_node* list_create(int arr[], int N);
t_node* list_copy(t_node *list);

t_node* list_append(t_node *a, t_node *b);
void    list_nconc(t_node *a, t_node *b);

void    list_print(t_node *list);
void    list_del(t_node *list);
void    list_del_rec(t_node *list);

// list over ints to produce int
int     list_foldr(t_node *list, int (*f)(int, int), int e);
int     list_foldl(t_node *list, int (*f)(int, int), int e);

/*

def foldr (f : a → b → b) (e : b) : List a → b
| []      => e
| x :: xs => f x (foldr f e xs)

def foldl (f : b → a → b) (e : b) : List a → b
| []      => e
| x :: xs => foldl f (f e x) xs

*/

