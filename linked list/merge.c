#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
}*first, *second;

int createll(struct Node *head, int l[], int n)
{
    struct Node *last, *t;
    head->data=l[0];
    head->next=NULL;
    last=head;

    for (int i = 1; i < n; i++)
    {
        t=malloc(sizeof(struct Node*));
        t->data=l[i];
        t->next=NULL;

        last->next=t;
        last=t;
    }
}

void display(struct Node *head)
{
    struct Node* t=head;
    while(t!=0)
    {
        printf("%d ", t->data);
        t=t->next;
    }
}

struct Node* mergell(struct Node *first, struct Node* second)
{
    struct Node *third=malloc(sizeof(struct Node*));
    struct Node *last=malloc(sizeof(struct Node*));
    struct Node *f=first;
    struct Node *s=second;
    
    if (f->data<s->data)
    {
        third=f;
        last=f;
        f=f->next;
        last->next=NULL;
    }
    else
    {
        third=s;
        last=s;
        s=s->next;
        last->next=NULL;
    }

    while(f!=NULL && s!=NULL)
    {
        if(f->data<s->data)
        {
            last->next=f;
            last=f;
            f=f->next;
            last->next=NULL;
        }
        else
        {
            last->next=s;
            last=s;
            s=s->next;
            last->next=NULL;
        }
    }
    if(f!=NULL)
        last->next=f;
    else
        last->next=s;
    return third;
}

void main()
{
    int ar1[]={1, 3, 4, 5, 7};
    int ar2[]={0, 2, 6, 8, 9};
    first=(struct Node*)malloc(sizeof(struct Node*));
    second=(struct Node*)malloc(sizeof(struct Node*));
    createll(first, ar1, 5);
    createll(second, ar2, 5);
    display(first);
    printf("\n");
    display(second);
    printf("\n");
    display(mergell(first, second));
}

