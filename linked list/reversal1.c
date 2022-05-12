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

void reversal()
{
    int *arr=malloc(6*sizeof(int));
    struct Node *t=first;
    int i=0;
    while(t!=NULL)
    {
        arr[i]=t->data;
        t=t->next;
        i++;
    }
    t=first;
    for(i=5; i>=0; i--)
    {
        t->data=arr[i]; 
        t=t->next;  
    }
}

void main()
{
    int arr[]={23, 22, 1, 3, 43, 18};
    createll(arr, 6);
    display();
    printf("\nAfter reversal-\n");
    reversal();
    display();
}