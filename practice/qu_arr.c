#include <stdio.h>
#include <stdlib.h>

struct Qnode
{
    int *arr;
    int front;
    int rear;
    int size;
    int cap;
};

struct Qnode* createqueue(int c)
{
    struct Qnode *q = (struct Qnode*)malloc(sizeof(struct Qnode));
    q->front = q->size = 0;
    q->rear = c - 1;
    q->cap = c;
    q->arr = (int *)malloc(q->cap * (sizeof(int)));
    return q;
}

int isFull(struct Qnode *q)
{
    if(q->size==q->cap)
    {
        printf("Queue is full.\n");
        return 1;
    }
    return 0;
}

int isEm(struct Qnode *q)
{
    if(q->size==0)
    {
        printf("Queue is empty.\n");
        return 1;
    }
    return 0;
}

void enq(struct Qnode* q, int d)
{
    if(isFull(q))
        return;
    q->rear = (q->rear + 1) % q->cap;
    q->arr[q->rear] = d;
    q->size++;
    printf("%d is enequeued in the queue.\n", d);
}

void deq(struct Qnode* q)
{
    if(isEm(q))
        return;
    int x = q->arr[q->front];
    q->front = (q->front + 1) % q->cap;
    q->size--;
    printf("%d is dequeued from the queue.\n", x);
}

void display(struct Qnode* q)
{
    if(isEm(q))
    {
        printf("No items to display.\n");
        return;
    }
    // printf("f=%d r=%d\n", q->front, q->rear);
    int i=q->front;
    int t = i;
    do
    {
        printf("%d ", q->arr[i]);
        t = i;
        i = (i + 1) % q->cap;
    } while (t != q->rear);
    printf("\n");
}

void main()
{
    printf("Enter queue capacity: ");
    int c;
    scanf("%d", &c);
    struct Qnode *top = createqueue(c);

    display(top);
    enq(top, 1);
    enq(top, 2);
    enq(top, 3);
    enq(top, 4);
    display(top);
    deq(top);
    display(top);
    enq(top, 5);
    display(top);
    enq(top, 5);
    deq(top);
    deq(top);
    deq(top);
    deq(top);

    deq(top);
    deq(top);
    display(top);

    enq(top, 6);
    display(top);
}