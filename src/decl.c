#include <stdio.h>

int main(void) {
  int* px, py, pz;
  int *pa, *pb, *pc;
  
  printf("px %lu py %lu pz %lu \n",
	 sizeof(px), sizeof(py), sizeof(pz));
  printf("pa %lu pb %lu pc %lu \n",
	 sizeof(pa), sizeof(pb), sizeof(pc));
}
