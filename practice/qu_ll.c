#include <stdio.h>
#include <stdlib.h>

struct Qnode
{
    int data;
    struct Qnode *next;
};

struct Qnode *createhead(struct Qnode **head, struct Qnode **rear, int d)
{
    *head = (struct Qnode *)malloc(sizeof(struct Qnode));
    (*head)->next = NULL;
    (*head)->data = d;
    (*rear) = (*head);
}

void enq(struct Qnode **head, struct Qnode **rear)
{
    int d;
    printf("Enter data: ");
    scanf("%d", &d);
    if (*head == NULL)
    {
        createhead(head, rear, d);
        return;
    }
    struct Qnode *new = (struct Qnode *)malloc(sizeof(struct Qnode));
    (*rear)->next = new;
    new->next = NULL;
    new->data = d;
    (*rear) = new;
}

void deq(struct Qnode **head)
{
    if (*head == NULL)
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
    if (head == NULL)
    {
        printf("No item to print.");
        return;
    }
    struct Qnode *t = head;
    while (t != NULL)
    {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

void main()
{
    struct Qnode *front = NULL;
    struct Qnode *rear = NULL;

    enq(&front, &rear);
    enq(&front, &rear);
    enq(&front, &rear);
    enq(&front, &rear);
    enq(&front, &rear);
    display(front);
    deq(&front);
    deq(&front);
    deq(&front);
    display(front);
    enq(&front, &rear);
    deq(&front);
    deq(&front);
    deq(&front);
    deq(&front);
    deq(&front);
    deq(&front);
    deq(&front);
    enq(&front, &rear);
    display(front);
    deq(&front);
    deq(&front);
    display(front);
}