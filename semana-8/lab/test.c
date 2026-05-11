#include <stdio.h>
#include <stdlib.h>
#include "list.h"


int is_odd(int n){
  if(n % 2 == 0)
    return 0;
  else
    return 1;
}


int main(int argc, char *argv[]) {

  int ar[] = {1,2,3};

  for(int i = 0; i < 3; i++){
    printf("ar[%d] = %d\n", i, ar[i]);
  }
  
  t_node* al = list_create(ar, 3);

  int n = list_size(al);
  int br[n];
  list_array(al, br, n);

  for(int i = 0; i < 3; i++){
    printf("br[%d] = %d\n", i, br[i]);
  }


  list_del(al);

  return 0;
}
