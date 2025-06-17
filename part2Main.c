#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

extern int pop();
extern void push(int);
extern int isEmpty();
extern void swap(int *, int *);
extern int heapSize();
extern int heapDelete();
extern void createMaxHeap(int[], int);
extern void addHeap(int);
extern void HeapPrint(int[], int, int);
extern int heap[100];

int main(int argc, char * argv[])
{
  int val;
  int counter = 0;
  fprintf(stdout, "Enter -101 to stop adding numbers.\n");
  
  if(scanf("%d", &val) != 1){ 
    fprintf(stderr, "Error: No number input.");
    exit(1);
  }

  while (val != EOF && val != -101) {
    fprintf(stderr, "Added: %d\n", val);
    addHeap(val);
	counter++;

    if(scanf("%d", &val) == 0){
      fprintf(stderr, "Error: No number input.");
      exit(1);

    }
  }

  fprintf(stdout, "\n");
  createMaxHeap(heap, counter); 
    HeapPrint(heap, counter, 0); 
	fprintf(stdout, "\n");
	fprintf(stdout, "\nDescending:\n"); 
	while (heapSize() > 0){ 
		int item = heapDelete();
		fprintf(stdout, "Deleted (heap): %d\n", item);
		push(item);
	}
	printf("\n");
    fprintf(stdout, "Ascending:\n");
 
	while (!isEmpty()){ 
    	int top = pop();
    	fprintf(stdout, "Popped (stack): %d\n", top);
	}
    exit(0); 
}
