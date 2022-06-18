#include <stdio.h>
#include <stdlib.h>

struct Dequ
{
    int *arr;
    int front;
    int rear;
    int size;
    // int cap;
};

struct Dequ *createdequ(int s)
{
    struct Dequ *q = (struct Dequ *)malloc(sizeof(struct Dequ));
    // q->cap = c;
    q->size = s;
    q->front = -1;
    q->rear = 0;
    q->arr = (int *)malloc(q->size * sizeof(int));
    return q;
}

int isFull(struct Dequ *q)
{
    return ((q->front == 0 && q->rear==q->size-1) || q->front==q->rear+1);
}

int isEm(struct Dequ *q)
{
    return (q->front == -1);
}

void insertF(struct Dequ *q, int d)
{
    if (isFull(q))
    {
        printf("The queue is full.\n");
        return;
    }

    if (q->front == -1)
    {
        q->front = 0;
        q->rear = 0;
    }

    else if (q->front == 0)
        q->front = q->size - 1;

    else
        q->front = q->front - 1;

    q->arr[q->front] = d;
}

void deleteF(struct Dequ* q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty.\n");
        return;
    }

    if (q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
    else
        if (q->front == q->size - 1)
            q->front = 0;

        else 
            q->front = q->front + 1;
}

void insertR(struct Dequ* q, int d)
{
    if (isFull(q))
    {
        printf("Queue is full.\n");
        return;
    }

    if (q->front == -1)
    {
        q->front = 0;
        q->rear = 0;
    }

    else if (q->rear == q->size - 1)
        q->rear = 0;

    else
        q->rear = q->rear + 1;

    q->arr[q->rear] = d;
}

void deleteR(struct Dequ* q)
{
    if (isEmpty(q))
    {
        printf("The queue is empty.");
        return;
    }
    
    if (q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
    else if (q->rear == 0)
        q->rear = q->size - 1;
    else
        q->rear = q->rear - 1;
}


void getRear(struct Dequ *q)
{
    if (!isEm(q))
        printf("%d\n", q->arr[q->rear + 1]);
    else
        printf("The queue is empty.\n");
}

void getFront(struct Dequ *q)
{
    if (!isEm(q))
        printf("%d\n", q->arr[q->front - 1]);
    else
        printf("The queue is empty.");
}

void display(struct Dequ *q)
{
    if (!isEm(q))
    {
        for (int i = 0; i < q->size; i++)
            printf("%d ", q->arr[i]);
        printf("\n");
    }
    else
        printf("No elements to display.\n");
}

void main()
{
    struct Dequ *dq = createdequ(10);
}