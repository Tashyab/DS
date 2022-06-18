#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int cap;
    int* arr;
};

struct Queue* createqu(int cap)
{
    struct Queue *qt=(struct Queue*)malloc(sizeof(struct Queue));
    qt->cap=cap;
    qt->size=0;
    qt->front=0;
    qt->rear=qt->cap-1;
    qt->arr=(int *)malloc(cap*sizeof(int));
    return qt;
}

int isEm(struct Queue *q)
{
    return (q->size==0);
}

int isFull(struct Queue *q)
{
    return (q->size==q->cap);
}

void getfront(struct Queue *q)
{
    if(!isEm(q))
    {
        printf("%d is front.\n", q->arr[q->front]);
    }
    else
        printf("Queue is empty.");
}

void getrear(struct Queue *q)
{
    if(!isEm(q))
        printf("%d is rear.\n", q->arr[q->rear]);
    else
    {
        printf("Queue is empty.");
    }
}

void enq(struct Queue *q, int d)
{
    if(isFull(q))
        printf("The queue is full.\n");
    else
    {
        q->rear=(q->rear+1)%q->cap;
        q->arr[q->rear]=d;
        q->size++;
        printf("%d is enqueued.\n", d);
    }
}

void deq(struct Queue *q)
{
    if(isEm(q))
        printf("The queue is empty.\n");
    else
    {
        int x=q->arr[q->front];
        q->front=(q->front+1)%q->cap;
        q->size--;
        printf("%d is dequeued.\n", x);
    }
}

void display(struct Queue* q)
{
    // printf("%d is front\n", q->front);
    if(q->size==0)
    {
        printf("The Queue is empty.\n");
        return;
    }
    for(int i=q->front; i<=q->rear; i++)
        printf("%d ", q->arr[i]);
    printf("\n");
}

void main()
{
    struct Queue *q=createqu(4);
    deq(q);
    enq(q, 1);
    enq(q, 3);
    enq(q, 5);
    enq(q, 7);
    enq(q, 9);
    display(q);
    deq(q);
    deq(q);
    display(q);
    enq(q, 9);
    deq(q);
    deq(q);
    deq(q);
    display(q);
    enq(q, 11);
    enq(q, 13);
    display(q);

}