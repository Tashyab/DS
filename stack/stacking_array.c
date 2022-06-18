#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    int *s;
};

void create(struct Stack *st)
{
    printf("Enter size: ");
    scanf("%d", &st->size);
    st->top=-1;
    st->s=(int*)malloc(st->size*sizeof(int));
}

void display(struct Stack st)
{
    for(int i=st.top; i>=0; i--)
    {
        printf("%d ", st.s[i]);
    }
    printf("\n");
}

void push(struct Stack *st, int x)
{
    if(st->top==st->size-1)
        printf("stack overflow");
    else
    {
        st->top++;
        st->s[st->top]=x;
    }
}

int pop(struct Stack *st)
{
    int x=-1;
    if(st->top==-1)
        printf("stack underflow");
    else
    {
        x=st->s[st->top];
        st->top--;
    }
    return x;
}

int peek(int in, struct Stack st)
{
    int x=-1;
    if(st.top-in+1<0)
        printf("Invalid position");
    else
        x=st.s[st.top-in+1];
    return x;
}

int stacktop(struct Stack st)
{
    if(st.top==-1)
        return -1;
    else 
        return st.s[st.top];
}

int isempty(struct Stack st)
{
    if(st.top==-1)
        return 1;
    else
        return 0;
}

int isfull(struct Stack st)
{
    if (st.top==st.size-1)
        return 1;
    else    
        return 0;
}

void main()
{
    struct Stack st;
    create(&st);
    push(&st, 23);
    push(&st, 33);
    push(&st, 43);
    push(&st, 53);
    push(&st, 63);

    // printf("%d\n", stacktop(st));
    display(st);

}