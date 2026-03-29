#include <stdio.h>
#include <stdlib.h>

int search(int *arr, int size, int value) {
  for (int i = 0; i < size; i++){
    if (arr[i] == value) {
      return i;
    }
  }
  return -1;

}

int* generate_array1() {
  static int arr[] = {1, 2, 3, 4, 5};
  return arr;
}


int* generate_array2() {
  int *arr = malloc(5 * sizeof(int));
  for(int i = 0; i < 5; i++)
    arr[i] = i + 1;
  return arr;
}

int main() {
  int a[] = {1,2,3,4,5,6,7,8,9,10};

  int r = search(a, 10, 3); // search for value 3
  printf("fount at %d\n", r);
  
  int *ptr = generate_array1();
  
  for (int i = 0; i < 5; i++) {
    printf("%d\n", ptr[i]); 
  }

  // if malloc was used with generate_array1?
  // free(ptr);

}
  
