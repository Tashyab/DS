#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
}*first;

void createll(struct Node *head, int l[], int n)
{
    struct Node *t, *last;
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
    t->next=head;
}

void display()
{
    struct Node *t=first;
    do
    {
        printf("%d ", t->data);
        t=t->next;
    } while (t!=first);

    // while(t->next!=first)
    // {
    //     printf("%d ", t->data);
    //     t = t->next;
    // }
}

void insertion_beforehead(int d)
{
    struct Node *n=malloc(sizeof(struct Node*));
    n->data=d;
    n->next=first;
    if(first==NULL)
    {
        first=n;
        first->next=first;
    }
    else
    {
        struct Node *p=first;
        while(p->next!=first)
            p=p->next;
        p->next=n;
        first=n;
    }

}

void deletion_ofhead()
{
    struct Node *t=first;
    struct Node *k=first;
    while(t->next!=first)
        t=t->next;
    t->next=k->next;
    first=k->next;
    free(k);
}

void main()
{
    int ar[]={1, 2, 3, 4, 5, 6, 7};
    first=malloc(sizeof(struct Node *));
    createll(first, ar, 7);
    display();
    printf("\n");
    insertion_beforehead(0);
    display();
    printf("\n");
    deletion_ofhead();
    display();
    printf("\n");
    insertion_beforehead(69);
    display();
}