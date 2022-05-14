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

    for (int i = 1; i < n; i++)
    {
        struct Node* t=(struct Node*) malloc(sizeof(struct Node*));
        t->data=l[i];
        t->next=NULL;

        last->next=t;
        last=t;
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

void delete(int in)
{
    struct Node *p, *q;
    if(in==1)
    {
        p=first;
        first=first->next;
        free(p);
    }
    else
    {
        p=first;
        q=NULL;
        for (int i = 0; i < in-1; i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        free(p);
    }
}

void main()
{
    int arr[]={23, 22, 1, 3, 43, 18};
    createll(arr, 6);
    display();
    delete(3);
    printf("\n");
    display();
}