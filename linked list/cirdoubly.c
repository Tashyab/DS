#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    struct Node *prev;
    int data;
    struct Node *next;
}*first;

void create(struct Node* head, int l[], int n)
{
    struct Node *last, *t;
    head->data=l[0];
    head->next=NULL;
    head->prev=NULL;
    last=head;

    for (int i = 1; i < n; i++)
    {
        struct Node *t=(struct Node*)malloc(sizeof(struct Node*));
        t->data=l[i];
        t->next=last->next;
        t->prev=last;

        last->next=t;
        last=t;
    }
    last->next=head;
    head->prev=last;
}

void display()
{
    struct Node *t=first;
    do
    {
        printf("%d ", t->data);
        t=t->next;
    } while(t!=first);
}

void insertion_beforehead(int d)
{
    struct Node *t=malloc(sizeof(struct Node*));
    t->data=d;
    t->prev=first->prev;
    t->next=first;
    first->prev->next=t;
    first->prev=t;
    first=t;
}

void deletion_thehead()
{
    struct Node *t=first;
    struct Node *k=first;
    t=t->next;
    t->prev=k->prev;
    k->prev->next=t;
    first=t;
    free(k);
}

void main()
{
    first=malloc(sizeof(struct Node*));
    int ar[]={1, 2, 3, 4, 5, 6, 7, 8};
    create(first, ar, 8);
    insertion_beforehead(0);
    insertion_beforehead(69);
    deletion_thehead();
    display();
}