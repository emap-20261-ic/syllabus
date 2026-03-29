typedef struct node t_node;

/* linked list */

int      list_nth(t_node *list, int n);
int      list_first(t_node *list);
int      list_size(t_node *list);
int      is_palindrome(t_node *list);
int      list_hasloop(t_node* head);

t_node*  list_rest(t_node *list);
t_node*  list_insert(int element, t_node* list);
t_node*  list_reverse(t_node *a);
t_node*  list_copy(t_node *list);
t_node*  list_append(t_node *a, t_node *b);
t_node*  list_create(int arr[], int N);

int*     list_array(t_node *list, int size);

void     list_filter(t_node **head, int (*f) (int));
void     list_nconc(t_node *a, t_node *b); 
void     list_print(t_node *list, char* sep);
void     list_del(t_node *list);
void     list_del_rec(t_node *list);

t_node*  merge_sorted(t_node *a, t_node *b);
void     list_split(t_node *source, t_node **a, t_node **b);
void     merge_sort(t_node **ref);
