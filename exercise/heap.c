/* example of binary heap */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define HEAP_SIZE 10

void insert(int val, int heap[], int counter);
void print_structure(int heap[], int start_index);

int main(void)
{
    int heap[HEAP_SIZE];
    int val = 0; /* insert data */

    srand(getpid());

    for(int i = 0; i < HEAP_SIZE; i++) {
        /* random integer */
        val = rand();

        insert(val, heap, i);
        printf("Insert [%d]: %d\n", i, val);
    }

    printf("\n");
    print_structure(heap, 1);

    return 1;
}

/* max-heap property */
void insert(int val, int heap[], int counter)
{
    int i = counter + 1;
    while( (i != 1) && (heap[i/2] < val) ) {
        heap[i] = heap[i/2];
        i = i/2;
    }
    heap[i] = val;
}

void print_structure(int heap[], int start_index)
{
    for(int i = start_index; i < HEAP_SIZE; i++) {
        printf("parent [%d]: %d\n", i, heap[i]);
        /* left node */
        if (i*2 < HEAP_SIZE) {
            printf("\tchild L [%d]: %d\n", i*2, heap[i*2]);
        }
        /* right node */
        if (i*2+1 < HEAP_SIZE) {
            printf("\tchild R [%d]: %d\n", i*2+1, heap[i*2+1]);
        }
    }
}
