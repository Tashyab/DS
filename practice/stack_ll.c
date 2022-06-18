#include <stdlib.h>
#include <stdio.h>

struct Snode
{
    int data;
    struct Snode *next;
};

void push(struct Snode **top)
{
    printf("Enter data: ");
    int d;
    scanf("%d", &d);
    struct Snode *t = (struct Snode *)malloc(sizeof(struct Snode));
    t->data = d;
    t->next = *top;
    *top = t;
    printf("%d is pushed.\n", d);
}

void pop(struct Snode **top)
{
    if(*top==NULL)
    {
        printf("Stack is empty.\n");
        return;
    }
    struct Snode *p = *top;
    int x = (*top)->data;
    *top = (*top)->next;
    printf("%d is popped.\n", x);
    free(p);
}

void display(struct Snode *top)
{
    if(top==NULL)
    {
        printf("Stack empty.\n");
        return;
    }
    struct Snode *t = top;
    while(t!=NULL)
    {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}
    

void main()
{
    struct Snode *top = NULL;

    //Test cases
    pop(&top);
    pop(&top);
    display(top);
    pop(&top);
    push(&top);
    push(&top);
    push(&top);
    pop(&top);
    pop(&top);
    pop(&top);
    pop(&top);
    display(top);
}