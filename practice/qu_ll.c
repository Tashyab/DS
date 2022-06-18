#include <stdio.h>
#include <stdlib.h>

struct Qnode
{
    int data;
    struct Qnode *next;
};

struct Qnode* createhead(struct Qnode **head, int d)
{
    *head = (struct Qnode *)malloc(sizeof(struct Qnode));
    (*head)->next = NULL;
    (*head)->data = d;
}

void enq(struct Qnode **head)
{
    int d;
    printf("Enter data: ");
    scanf("%d", &d);
    if(*head==NULL)
    {
        createhead(head, d);
        return;
    }
    struct Qnode *t = *head;
    while(t->next!=NULL)
    {
        t = t->next;
    }
    struct Qnode *new =(struct Qnode*) malloc(sizeof(struct Qnode));
    t->next = new;
    new->next = NULL;
    new->data = d;
}

void deq(struct Qnode **head)
{
    if(*head==NULL)
    {
        printf("No data to dequeue.\n");
        return;
    }
    struct Qnode *p = *head;
    *head = (*head)->next;
    int x = p->data;
    printf("%d is dequeued.\n", x);
    free(p);
}

void display(struct Qnode *head)
{
    if(head==NULL)
    {
        printf("No item to print.");
        return;
    }
    struct Qnode *t = head;
    while(t!=NULL)
    {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

void main()
{
    struct Qnode *front = NULL;
    enq(&front);
    enq(&front);
    enq(&front);
    enq(&front);
    enq(&front);
    display(front);
    deq(&front);
    deq(&front);
    deq(&front);
    display(front);
    enq(&front);
    deq(&front);
    deq(&front);
    deq(&front);
    deq(&front);
    deq(&front);
    deq(&front);
    deq(&front);
    enq(&front);
    display(front);
    deq(&front);
    deq(&front);
    display(front);
}