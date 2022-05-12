#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
}*first;

int max(struct Node*t)
{
    int max=0;
    while(t!=0)
    {
        if(t->data>max)
        {
            max=t->data;
        }
        t=t->next;
    }
    return max;
}

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
void main()
{
    int arr[]={1, 23, 43, 232, 33, 22, 4};
    createll(arr, 7);
    printf("%d", max(first));
}