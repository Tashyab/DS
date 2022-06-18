#include <stdio.h>
#include <stdlib.h>

struct Dequ 
{
    int *arr;
    int front;
    int rear;
    int size;
    int cap;
};

struct Dequ* createdequ(int c)
{
    struct Dequ *q=(struct Dequ*)malloc(sizeof(struct Dequ));
    q->cap=c;
    q->size=q->front=0;
    q->rear=q->cap-1;
    q->arr=(int*)malloc(q->cap*sizeof(int));
    return q;
}

int isFull(struct Dequ *q)
{
    return (q->size==q->cap);
}

int isEm(struct Dequ *q)
{
    return (q->size==0);
}

void enqfront(struct Dequ *q, int d)
{
    if(isFull(q))
    {
        printf("Queue is full.\n");
        return;
    }
    for (int i = q->front-1; i >= 0; i--)
        q->arr[i+1] = q->arr[i];

    q->arr[0] = d;
    q->front++;
    q->size++;
    printf("%d is enqueued in front.\n", d);
}

void deqfront(struct Dequ* q)
{
    if(isEm(q))
    {
        printf("Queue is empty.\n");
        return;
    }
    int x = q->arr[0];
    for (int i = 0; i < q->front-1; i++)
        q->arr[i] = q->arr[i + 1];
    q->arr[--q->front] = -1;
    q->size--;
    printf("%d is dequeued from front.\n", x);
}

void enqrear(struct Dequ* q, int d)
{
    if(isFull(q))
    {
        printf("Queue is Full.\n");
        return;
    }
    for (int i = q->rear; i < q->cap-1; i++)
        q->arr[i] = q->arr[i + 1];

    q->arr[q->cap - 1] = d;
    q->rear--;
    q->size++;
    printf("%d is enqueued at rear.\n", d);
}

void deqrear(struct Dequ* q)
{
    if(isEm(q))
    {
        printf("Queue is empty.\n");
        return;
    }
    int x = q->arr[q->cap - 1];
    for (int i = q->cap - 1; i > q->rear+1; i--)
        q->arr[i] = q->arr[i - 1];

    q->arr[++q->rear] = -1;
    q->size--;
    printf("%d is dequeued from rear.\n", x);
}

void getRear(struct Dequ* q)
{
    if(!isEm(q))
        printf("%d\n", q->arr[q->rear + 1]);
    else
        printf("The queue is empty.\n");
}

void getFront(struct Dequ* q)
{
    if(!isEm(q))
        printf("%d\n", q->arr[q->front - 1]);
    else
        printf("The queue is empty.");
}

void display(struct Dequ* q)
{
    if(!isEm(q))
    {
        for (int i = 0; i < q->cap; i++)
            printf("%d ", q->arr[i]);
        printf("\n");
    }
    else
        printf("No elements to display.\n");
}

void main()
{
    struct Dequ *dq = createdequ(6);

    //Test 1

    // deqfront(dq);
    // deqrear(dq);
    // enqfront(dq, 4);
    // enqfront(dq, 2);
    // enqfront(dq, 6);
    // enqfront(dq, 1);
    // display(dq);
    // enqrear(dq, 7);
    // enqrear(dq, 8);
    // enqrear(dq, 9);
    // display(dq);
    // enqfront(dq, 10);
    // enqfront(dq, 11);
    // enqrear(dq, 13);
    // display(dq);
    // enqfront(dq, 5);
    // enqrear(dq, 3);
    // deqfront(dq);
    // display(dq);
    // deqrear(dq);
    // display(dq);
    // enqfront(dq, 3);
    // enqrear(dq, 5);
    // display(dq);

    enqfront(dq, 1);
    enqfront(dq, 2);
    enqfront(dq, 3);
    enqfront(dq, 4);
    enqfront(dq, 5);
    enqfront(dq, 6);
    enqfront(dq, 7);
    printf("%d %d \n", dq->rear, dq->front);
    deqrear(dq);
    deqrear(dq);
    display(dq);
}