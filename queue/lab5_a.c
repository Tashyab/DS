#include <stdio.h>
#include <stdlib.h>

struct Qnode
{
    struct Qnode *prev;
    int data;
    struct Qnode *next;
};

struct Queue
{
    struct Qnode *front, *rear;
};

struct Qnode *createnode(int d)
{
    struct Qnode *sq = (struct Qnode *)malloc(sizeof(struct Qnode));
    sq->data = d;
    sq->next = NULL;
    sq->prev = NULL;
}

struct Queue *createqu()
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqfront(struct Queue *q, int d)
{
    struct Qnode *t = createnode(d);
    if (q->rear == NULL)
    {
        q->front = q->rear = t;
        printf("%d enqueued at front.\n", d);
        return;
    }
    t->next = q->front;
    q->front->prev = t;
    q->front = t;
    printf("%d enqueued at front.\n", d);
}

void deqfront(struct Queue *q)
{
    if (q->front == NULL)
    {
        printf("Queue empty.\n");
        return;
    }

    struct Qnode *qn = q->front;
    int d = q->front->data;

    if (q->front->next == NULL)
    {
        q->front = q->rear = NULL;
    }
    else
    {
        q->front->next->prev = NULL;
        q->front = q->front->next;
    }
    printf("%d dequeued from front. \n", d);
    free(qn);
}

void enqend(struct Queue *q, int d)
{
    struct Qnode *t = createnode(d);
    if (q->rear == NULL)
    {
        q->front = q->rear = t;
        printf("%d enqueued at end.\n", d);
        return;
    }
    t->prev = q->rear;
    q->rear->next = t;
    q->rear = t;
    printf("%d enqueued at end.\n", d);
}

void deqend(struct Queue *q)
{
    if (q->front == NULL)
    {
        printf("Queue empty.\n");
        return;
    }
    struct Qnode *qn = q->rear;
    int d = q->rear->data;

    if (q->rear->prev == NULL)
    {
        q->rear = q->front = NULL;
    }
    else
    {
        q->rear->prev->next = NULL;
        q->rear = q->rear->prev;
    }
    free(qn);
    printf("%d dequeued from rear.\n", d);
}

void dis_f(struct Queue *q)
{
    if (q->front == NULL)
    {
        printf("No data to display\n");
        return;
    }
    struct Qnode *t = q->front;
    while (t != NULL)
    {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

void dis_r(struct Queue *q)
{
    if (q->rear == NULL)
    {
        printf("No data to display\n");
        return;
    }
    struct Qnode *t = q->rear;
    while (t != NULL)
    {
        printf("%d ", t->data);
        t = t->prev;
    }
    printf("\n");
}

void main()
{
    struct Queue *q = createqu();

    // Test cases
    deqfront(q);
    deqend(q);

    enqfront(q, 1);
    enqfront(q, 2);
    enqfront(q, 3);
    enqend(q, 4);
    enqend(q, 5);
    dis_f(q);
    dis_r(q);

    deqfront(q);
    deqfront(q);
    dis_f(q);

    deqend(q);
    deqend(q);
    dis_f(q);

    deqend(q);
    dis_r(q);
    deqfront(q);
    dis_f(q);
    dis_r(q);

    enqend(q, 4);
    dis_r(q);
    deqend(q);
    deqend(q);
    printf("\n\n\n\n\n\n\n\n\n\n\n\n");

    printf("Choices-\n\tEnter 1 for enquing at front.\n\tEnter 2 for enquing at end.\n\t");
    printf("Enter 3 for dequing at front.\n\tEnter 4 for dequing at end.\n\t");
    printf("Enter 5 for displaying from front.\n\tEnter 6 for displaying from end.\n\tAnd any other to exit.");

    int n;
    int in;
    while (1)
    {
        printf("\nEnter Choice: ");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
        {
            printf("Enter the data to enque at front: ");
            scanf("%d", &in);
            enqfront(q, in);
            break;
        }

        case 2:
        {
            printf("Enter the data to enque at end: ");
            scanf("%d", &in);
            enqend(q, in);
            break;
        }

        case 3:
        {
            deqfront(q);
            break;
        }

        case 4:
        {
            deqend(q);
            break;
        }

        case 5:
        {
            dis_f(q);
            break;
        }

        case 6:
        {
            dis_r(q);
            break;
        }

        default:
        {
            printf("Wrong choice.");
            exit(0);
        }
        }
    }
}
