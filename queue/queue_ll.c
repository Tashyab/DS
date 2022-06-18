#include <stdio.h>
#include <stdlib.h>

struct Qnode
{
    int data;
    struct Qnode *next;
};

struct Queue
{
    struct Qnode *front, *rear;
};

struct Qnode* createnode(int d)
{
    struct Qnode* qt=(struct Qnode*)malloc(sizeof(struct Qnode));
    qt->data=d;
    qt->next=NULL;
    return qt;
}

struct Queue* createqu()
{
    struct Queue* q=(struct Queue*)malloc(sizeof(struct Queue));
    q->front=q->rear=NULL;
    return q;
}

void enq(struct Queue* q, int d)
{
    struct Qnode* qnt=createnode(d);
    if(q->rear==NULL)
    {
        q->front=q->rear=qnt;
        printf("%d is enqueued\n", d);
        return;
    }
    q->rear->next=qnt;
    q->rear=qnt;
    printf("%d is enqueued\n", d);
}

void deq(struct Queue *q)
{
    if(q->front==NULL)
    {
        printf("Queue is empty.\n");
        return;
    }
    struct Qnode *t=q->front;
    int d=q->front->data;
    q->front=q->front->next;
    
    if(q->front==NULL)
        q->rear=NULL;

    free(t);
    printf("%d is dequeued\n", d);
}

void display(struct Queue *q)
{
    struct Qnode *t=q->front;
    while(t!=NULL)
    {
        printf("%d ", t->data);
        t=t->next;
    }
    printf("\n");
}

void main()
{
    struct Queue *head=createqu();
    enq(head, 10);
    enq(head, 20);
    enq(head, 30);
    display(head);
    enq(head, 40);
    display(head);
    deq(head);
    deq(head);
    display(head);
    deq(head);
    deq(head);
    display(head);
    deq(head);
    deq(head);
    enq(head, 50);
    display(head);
    deq(head);
    enq(head, 100);
    deq(head);
    deq(head);
}