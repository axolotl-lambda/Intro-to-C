#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

typedef struct Queue
{
    unsigned int length;
    unsigned int capacity;
    int *storage;
} Queue;

/*
    Creates a queue by allocating the appropriate amount of memory for an
    instance of the Queue struct, and initializes all of the fields of the
    struct. Also allocates memory for the queue's storage structure. 
*/
Queue *createQueue(unsigned capacity)
{
    Queue *new_queue = malloc(sizeof(Queue));
    new_queue->length = 0;
    new_queue->capacity = capacity;
    new_queue->storage = malloc(sizeof(int) * capacity);
    return new_queue;
}

/*
    Adds the given item to the end of the queue. If the queue does
    not have room, expand the queue's available storage so that it 
    does have room for the additional item.
*/
void enqueue(Queue *q, int item)
{
    printf("\n"); // if i remove this the code crashes don't ask me why
    // first check if capacity is large enough, then expand if need be
    if ((q->length + 1) == q->capacity)
    {
        q->storage = realloc(q->storage, (q->capacity * 2));
    }
    // then add item
    q->length++;
    q->storage[q->length] = item;
}

/*
    Removes the item at the front of the queue and returns it. 
    If the queue is empty, this function should return -1.
*/
int dequeue(Queue *q)
{
    // check if no items, if so return -1
    if (q->length == 0)
    {
        return -1;
    }
    // grab item, then shift all other items
    int *item = q->storage;
    for (int i = 0; i < q->length; i++)
    {
        q->storage[i] = q->storage[i + 1];
    }
    q->length--;
    return *item;
}

/*
    Frees the memory used to hold the queue instance and its
    associated storage. 
*/
void destroyQueue(Queue *q)
{
    if (q->storage != NULL)
    {
        free(q->storage);
    }
    if (q != NULL)
    {
        free(q);
    }
}

#ifndef TESTING
int main(void)
{
    Queue *q = createQueue(4);

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    enqueue(q, 6);

    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));

    destroyQueue(q);

    return 0;
}
#endif