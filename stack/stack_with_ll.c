#include <stdio.h>
#include <stdlib.h>

struct SNode
{
    int data;
    struct SNode *next;
};

void push(struct SNode **top, int d)
{
    struct SNode *t=(struct SNode*)malloc(sizeof(struct SNode));
    t->data=d;
    t->next=*top;
    *top=t;
    printf("%d is pushed.\n", d);
}

void pop(struct SNode **top)
{
    if(*top==NULL)
        printf("Stack is empty.\n");
    else
    {
        struct SNode *t=*top;
        int x=t->data;
        *top=(*top)->next;
        free(t);
        printf("%d is popped.\n", x);
    }
}

int main()
{
    struct SNode *head=(struct SNode*) malloc(sizeof(struct SNode));
    head=NULL;
    pop(&head);
    push(&head, 20);
    push(&head, 30);
    pop(&head);
    push(&head, 40);
    push(&head, 50);
    pop(&head);
    push(&head, 60);
    pop(&head);
    pop(&head);
    pop(&head);
    pop(&head);
    pop(&head);
    pop(&head);
    push(&head, 10);
    push(&head, 120);
    return 0;
}