#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int cap;
    int top;
    int *arr;
};

struct Stack *createstack(int c)
{
    struct Stack *st = (struct Stack*)malloc(sizeof(struct Stack));
    st->cap = c;
    st->arr = malloc(sizeof(int) * st->cap);
    st->size = st->top = 0;
    return st;
}

int isFull(struct Stack *st)
{
    if(st->cap == st->size)
    {
        printf("Stack is full.\n");
        return 1;
    }
    return 0;
}

int isEmpty(struct Stack *st)
{
    if(st->size==0)
    {
        printf("Stack is Empty.\n");
        return 1;
    }
    return 0;
}

void push(struct Stack *st, int d)
{
    if(isFull(st))
        return;
    st->arr[st->top++] = d;
    st->size++;
    printf("%d is pushed.\n", d);
}

void pop(struct Stack *st)
{
    if(isEmpty(st))
        return;
    int x = st->arr[--st->top];
    st->size--;
    printf("%d is popped out.\n", x);
}

void display(struct Stack *st)
{
    if(isEmpty(st))
        return;
    for (int i = 0; i < st->size; i++)
        printf("%d ", st->arr[i]);
    printf("\n");
}

int main()
{
    printf("Enter the stack capacity: ");
    int c;
    scanf("%d", &c);
    struct Stack *st=createstack(c);

    //Test Cases
    display(st);
    push(st, 1);
    push(st, 2);
    push(st, 3);
    push(st, 4);
    pop(st);
    display(st);
    push(st, 5);
    push(st, 5);
    display(st);
    pop(st);
    pop(st);
    pop(st);
    pop(st);

    pop(st);
    pop(st);
    display(st);

    push(st, 5);
    display(st);
    return 0;
}
