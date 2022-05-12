#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;

}*first;

int createll(int l[], int n)
{
    first=(struct Node*)malloc(sizeof(struct Node*));
    struct Node *last, *t;
    first->data=l[0];
    first->next=NULL;
    last=first;

    for (int i = 0; i < n; i++)
    {
        struct Node* t=(struct Node*) malloc(sizeof(struct Node*));
        t->data=l[i];
        t->next=NULL;

        last->next=t;
        last=t;
    }
}

void insert(int d, int in)
{
    
    struct Node *t=(struct Node*) malloc(sizeof(struct Node*));
    struct Node *p=first;
    t->data=d;
    if(in==0)
    {
        t->next=first;
        first=t;
    }
    else
    {
        for (int i = 0; i < in-1 && p; i++)
        {
            p=p->next;
        }
        if(p)
        {
            t->next=p->next;
            p->next=t; 
        }
    }
}

void display()
{
    struct Node *t=first;
    while(t!=0)
    {
        printf("%d ", t->data);
        t=t->next;
    }
}

void main()
{
    int arr[]={23, 22, 1, 3, 43, 18};
    createll(arr, 7);
    display();
    printf("\n");
    insert(21, 3);
    insert(10, 0);
    display();
}