#include <stdio.h>
#define MAX 5

typedef struct
{
    int data[MAX];
    int head, tail;
} Queue;

void enqueue(Queue *q, int item);
int dequeue(Queue *q);
int main()
{
    Queue q;
    int item;
    q.head = 0;
    q.tail = 0;
    enqueue(&q, 10);
    printf("tail: %d\n", q.tail);
    enqueue(&q, 20);
    printf("tail: %d\n", q.tail);
    enqueue(&q, 30);
    printf("tail: %d\n", q.tail);

    item = dequeue(&q);
    printf("Dequeued item is %d\n", item);
    item = dequeue(&q);
    printf("Dequeued item is %d\n", item);
    item = dequeue(&q);
    printf("Dequeued item is %d\n", item);
    item = dequeue(&q);
    printf("Dequeued item is %d\n", item);
    return 0;
}

void enqueue(Queue *q, int item)
{
    if ((q->tail + 1) % (MAX + 1) == q->head)
    {
        printf("Queue is full!\n");
        return;
    }
    q->data[q->tail] = item;
    q->tail = (q->tail + 1) % (MAX + 1);
}
int dequeue(Queue *q)
{
    int item;
    if (q->head == q->tail)
    {
        printf("Queue is empty!\n");
        return -1;
    }
    item = q->data[q->head];
    q->head = (q->head + 1) % (MAX + 1);
    return item;
}