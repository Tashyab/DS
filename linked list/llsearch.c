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

int search(struct Node *t, int n)
{
    struct Node *p = t;
    while (p!=NULL) 
    {
        if(p->data==n)
            return 1;
        else
            p=p->next;
    }
    return 0;
}

void main()
{
    int arr[]={23, 22, 1, 3, 43, 18};
    createll(arr, 7);
    if(search(first, 388))
        printf("present");
    else
        printf("absent");
}