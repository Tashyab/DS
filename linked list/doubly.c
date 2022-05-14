#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    struct Node *prev;
    int data;
    struct Node *next;
}*first;

void createdll(struct Node *head, int l[], int n)
{
    struct Node *last, *t;
    head->data=l[0];
    head->next=NULL;
    head->prev=NULL;
    last=head;

    for (int i = 1; i < n; i++)
    {
        struct Node* t=(struct Node*) malloc(sizeof(struct Node*));
        t->data=l[i];
        t->next=last->next;
        t->prev=last;

        last->next=t;
        last=t;
    }
}

void insertion(int ind, int d)
{
    struct Node *p=first;
    struct Node *t=malloc(sizeof(struct Node*));
    t->data=d;
    if(ind==0)
    {
        t->next=first;
        t->prev=NULL;
        first->prev=t;
        first=t;
    }
    else
    {
        for (int i = 0; i < ind-1; i++)
        {
            p=p->next;
        }
        t->next=p->next;
        t->prev=p;
        if(p->next)
            p->next->prev=t; 
        p->next=t;
    }
}

void deletion(int ind)
{
    struct Node *t;
    if(ind==1)
    {
        t=first;
        first=first->next;
        free(t);
        if(first)
            first->prev=NULL;
    }
    else
    {
        for (int i = 0; i < ind-1; i++)
        {
            t=t->next;
        }
        t->prev->next=t->next;
        if(t->next)
            t->next->prev=t->prev;
        free(t);
    }
}

void reversal()
{
    struct Node *p=first;
    struct Node *temp=malloc(sizeof(struct Node*));
    while(p!=NULL)
    {
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        p=p->prev;
        if(p!=NULL && p->next==NULL)
            first=p;
    }
}

void display()
{
    struct Node* t=first;
    while(t!=0)
    {
        printf("%d ", t->data);
        t=t->next;
    }
}

void main()
{
    int ar[]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    first=malloc(sizeof(struct Node*));
    createdll(first, ar, 10);
    insertion(0, -1);
    insertion(11, 10);
    deletion(1);
    deletion(10);
    reversal();
    display();
}