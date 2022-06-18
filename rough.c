#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int ifempty(struct stack *sp)
{
    return (sp->top == -1);
}

int iffull(struct stack *sp)
{
    return (sp->top == sp->size - 1);
}

void push(struct stack *sp, char x)
{
    if (iffull(sp))
    {
        printf("stack overflow");
    }
    else
    {
        sp->top = sp->top + 1;
        sp->arr[sp->top] = x;
    }
}

char pop(struct stack *sp)
{
    if (ifempty(sp))
    {
        printf("stack is empty");
        return -1;
    }
    else
    {
        char n = sp->arr[sp->top];
        sp->top = sp->top - 1;
        return n;
    }
}

int match(char a, char b)
{
    return ((a == '{' && b == '}') || (a == '[' && b == ']') || (a == '(' && b == ')'));
}

void display(struct stack* sp)
{
    printf("%c", sp->arr[sp->top]);
}

int parathen(char *exp)
{
    struct stack *sp=(struct stack*)malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    int i;
    char poped_ch;
    for (i = 0; i<strlen(exp); i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(sp, exp[i]);
            // display(sp);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (ifempty(sp))
            {
                return 0;
            }
            poped_ch = pop(sp);
            if (!match(poped_ch, exp[i]))
            {
                return 0;
            }
            // display(sp);
        }
    }
    if (ifempty(sp))
    {
        return 1;
    }
    return 0;
}

int main()
{
    char *exp = "(8)(9-3)";
    // int parathen(char *exp);
    if (parathen(exp))
    {
        printf("It is matching");
    }
    else
    {
        printf("It is not matching");
    }
    return 0;
}