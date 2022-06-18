#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *next;
};

struct Node* createll()
{
    int d;
    struct Node *last, *t;
    printf("Enter value 1 of linked list or enter -1 to quit: ");
    scanf("%d", &d);
    if(d==-1)
        return NULL;
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    head->data = d;
    head->next = NULL;
    last = head;
    int i = 2;
    while(d!=-1)
    {
        printf("Enter value %d or enter -1 to quit: ", i++);
        scanf("%d", &d);
        if(d!=-1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = d;
            t->next = NULL;
            last->next = t;
            last = t;
        }
    }
    return head;
}

void display(struct Node *head)
{
    if(head==NULL)
        return;
    struct Node *t = head;
    while(t!=NULL)
    {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

void reverse(struct Node **head)
{
    if(*head==NULL)
        return;
    struct Node *prev = NULL, *current = *head, *after = NULL;
    while (current!=NULL)
    {
        after = prev;
        prev = current;
        current = current->next;
        prev->next = after;
    }
    *head = prev;
}

void main()
{
    struct Node *head = createll();
    display(head);
    reverse(&head);
    display(head);
}
