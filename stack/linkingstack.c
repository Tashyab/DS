#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void push(struct Node **top, int d)
{
    struct Node* t=(struct Node*)malloc(sizeof(struct Node));
    t->data=d;
    t->next=*top;
    *top=t;
    printf("Item pushed\n");
}

int pop(struct Node **top)
{
    struct Node *t;
    int x=-1;
    if(*top==NULL)
        printf("Stack is empty\n");
    else
    {
        t=*top;
        x=t->data;
        *top=(*top)->next;
        free(t);
    }
    return x;
}

void display(struct Node* top)
{
    struct Node *p=top;
    while(p!=NULL)
    {
        printf("%d ", p->data);
        p=p->next;
    }
    printf("\n");
}

void main()
{
    struct Node *top=malloc(sizeof(struct Node));
    top->data=1;
    top->next=NULL;
    push(&top, 10);
    printf("%d is popped\n", pop(&top));
    push(&top, 20);
    push(&top, 30);
    printf("%d is popped\n", pop(&top));
    printf("%d is popped\n", pop(&top));
    printf("%d is popped\n", pop(&top));
    printf("%d is popped\n", pop(&top));
    push(&top, 40);
    display(top);
}