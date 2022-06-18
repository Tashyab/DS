#include<stdio.h>
#include<stdlib.h>

struct Stack
{
    int *arr;
    int top;
    int cap;
    int size;
};

struct Stack* mystack(int c)
{
    struct Stack* t=(struct Stack*)malloc(sizeof(struct Stack));
    t->size=0;
    t->cap=c;
    t->top=-1;
    t->arr=(int*)malloc(sizeof(int)*c);
    return t;
}

void push(struct Stack*t, int d)
{
    if(t->size<t->cap)
    {  
        t->top++;
        t->size++;
        t->arr[t->top]=d;
        printf("Data pushed.\n");
    }
    else
        printf("Stack Full.\n");
}

void pop(struct Stack*t)
{
    if(t->size>0)
    {
        int x=t->arr[t->top];
        t->top--;
        t->size--;
        printf("%d is popped out.\n", x);
    }
    else
        printf("Stack empty.\n");
}

void display(struct Stack *t)
{
    struct Stack *p = t;
    for (int i = 0; i < p->size; i++)
    {
        printf("%d ", p->arr[i]);
    }
    printf("\n");
}

int main()
{
    struct Stack *st=mystack(4);
    push(st, 3);
    push(st, 4);
    push(st, 5);
    push(st, 6);
    push(st, 7);
    push(st, 8);
    push(st, 9);
    display(st);
    pop(st);
    pop(st);
    pop(st);
    pop(st);
    pop(st);
    pop(st);
    push(st, 8);
    push(st, 9);
    pop(st);
    return 0;
}
