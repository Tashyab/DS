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
        struct Node* t=(struct Node*) malloc(sizeof(struct Node*));
        t->data=l[i];
        t->next=NULL;

        last->next=t;
        last=t;
    }
}
void display(struct Node* head)
{
    struct Node* t=head;
    while(t!=0)
    {
        printf("%d ", t->data);
        t=t->next;
    }
}

struct Node* catll(struct Node* head_f, struct Node* head_s)
{
    struct Node *t=head_f;
    while(t->next!=0)
    {
        t=t->next;
    }
    t->next=head_s;
    second=NULL;
    struct Node* third=first;
    return third;
}

void main()
{
    first=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    int arr[]={32, 3, 2};
    createll(first, arr, 3);
    int arr2[]={1, 5, 98, 33};
    createll(second, arr2, 4);
    display(first);
    printf("\n");
    display(second);
    printf("\n");
    display(catll(first, second));
}