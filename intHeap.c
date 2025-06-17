#include <stdio.h>
#include <stdlib.h>
/**
 *  The functions in this module implement a Heapdata structure
 *  of integers.
 */
int heap[100];
int size = 0;

void swap (int * x, int * y){ 
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void heapify (int heap[], int size, int i){ 
	int highest = i; 
	int l= 2 * i +1;
	int r = 2 * i +2;
	

	if (l < size && heap[l] > heap[highest]){
		highest = l;
	}
	else {
		highest = i;
	}

	if (r < size && heap[r] > heap[highest]){
		highest = r;
	}

	if (highest != i){
		swap (&heap[i], &heap[highest]); 
		heapify (heap, size, highest);  
	}
}


/**
 * heapDelete() removes the biggest integer in the heap and returns it.
 *
 */

int heapDelete()
{
	int max;
	if (size == 0){
		fprintf(stderr, "Empty heap.\n");
        exit(1);
	}
	max = heap[0];
	heap[0] = heap [size - 1];
	size--;
	heapify (heap, size, 0);
	return max;
}
/**  addHeap(thing2add) adds the "thing2add" to the Heap.
 *
 */
void addHeap(int thing2add)
{
	int i;
	if (size >= 100) {
        fprintf(stderr, "Full heap.\n");
        exit(1);
    }
    heap[size] = thing2add;
    i = size;

    while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
        swap(&heap[(i - 1) / 2], &heap[i]);
        i = (i - 1) / 2;
    }
    size++;	
}
/**
 * heapSize() returns the number of items in the Heap.
 *
 */
int heapSize()
{
  return size;  //A dummy return statement
}

void createMaxHeap (int heap[], int size){
	int heapsize = size;
	
	for (int j = heapsize/2 - 1 ; j >= 0; j--){
		heapify(heap, heapsize, j);
	}
}
void HeapPrint(int heap[], int size, int i) {
    if (i >= size) {
		return;
	}
        printf("<node id=\"%d\">", heap[i]);
        HeapPrint(heap, size, 2 * i + 1);
        HeapPrint(heap, size, 2 * i + 2);
        printf("</node>");
}
