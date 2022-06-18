#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Snode
{
    char data;  
    struct Snode* next;
    int size;
};

void push(struct Snode** top, char d)
{
    struct Snode* t=(struct Snode*)malloc(sizeof(struct Snode));
    t->data=d;
    t->next=*top;
    *top=t;
    t->size++;
    // printf("%c is pushed.", d);
}

char pop(struct Snode** top)
{
    char ch;
    if(*top==NULL)
        return ' ';
    else
    {
        struct Snode *t=*top;
        ch=t->data;
        *top=(*top)->next;
        t->size--;
        free(t);
    }
    // printf("%c is popped.", ch);
    return ch;
}

int checker(char a, char b)
{
    return ((a=='[' && b==']') || (a=='{' && b=='}') || (a=='(' && b==')'));
}


void main()
{
    struct Snode *top=(struct Snode*)malloc(sizeof(struct Snode));
    top=NULL;
    char br[100];
    printf("Enter the bracket string: ");
    gets(br);
    int i=0;
    int flag=0;
    while(i<strlen(br))
    {
        if(br[i]=='[' || br[i]=='{' || br[i]=='(')
        {
            push(&top, br[i]);
        }
        else if(br[i] == ']' || br[i] == '}' || br[i] == ')')
        {
            if(checker(pop(&top), br[i])!=1)
            {
                flag=1;
                break;
            }
        }
        i++;
    }

    if(!flag && top->size==0)
        printf("\nThe brackets closed.");
    else
        printf("\nThe brackets are not properly closed.");
        
}