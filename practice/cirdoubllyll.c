#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

void createhead(struct Node** head, int d)
{
    *head = (struct Node *)malloc(sizeof(struct Node));
    (*head)->data = d;
    (*head)->next = (*head)->prev = *head;
    printf("%d is inserted at position 0.\n", d);
}

void insert(struct Node** head)
{
    int d, k;
    printf("Enter data to insert: ");
    scanf("%d", &d);
    printf("Enter position to insert: ");
    scanf("%d", &k);

    if(*head==NULL)
    {
        createhead(head, d);
        return;
    }

    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = d;
    struct Node *move = *head;
    int i;
    if(k==0)
    {
        t->prev = (*head)->prev;
        t->next = *head;
        (*head)->prev->next = t;
        (*head)->prev = t;
        *head = t;
    }
    else
    {
        for (i = 1; i < k+1; i++)
        {
            move = move->next;
            if(move==(*head))
                break;
        }
        t->prev = move->prev;
        t->next = move;
        move->prev->next = t;
        move->prev = t;
    }
    printf("%d is inserted at position %d.\n", d, i);
}

void delete(struct Node** head)
{
    int k;
    printf("Enter position to delete: ");
    scanf("%d", &k);
    if(*head==NULL)
    {
        printf("No element to delete.\n");
        return;
    }
    struct Node *t, *move=(*head);
    int x, i;
    if((*head)->prev==(*head))
        *head = NULL;
    else if (k == 0)
    {
        t = *head;
        x = t->data;
        printf("here\n");
        (*head)->prev->next = (*head)->next;
        (*head)->next->prev = (*head)->prev;
        (*head) = (*head)->next;
        free(t);
    }
    else
    {
        for (i = 0; i < k; i++)
        {
            move = move->next;
            if(move==(*head))
            {
                move = move->prev;
                break;
            }
        }
        t = move;
        x = t->data;
        move->prev->next = move->next;
        move->next->prev = move->prev;
        free(t);
    }
    printf("%d is deleted from position %d.\n", x, i);
}

void dis(struct Node *head)
{
    if(head==NULL)
    {
        printf("No element to display.\n");
        return;
    }
    struct Node *t = head;
    do
    {
        printf("%d ", t->data);
        t=t->next;
    } while (t != head);
    printf("\n");
}

void disback(struct Node *head)
{
    if(head==NULL)
    {
        printf("No element to display.\n");
        return;
    }
        struct Node *t = head;
        do
        {
            t = t->prev;
            printf("%d ", t->data);
    } while (t != head);
    printf("\n");
}

void main()
{
    struct Node *head = NULL;

    //Test Cases
    // dis(head);
    // disback(head);
    // insert (&head);
    // insert (&head);
    // insert (&head);
    // insert (&head);
    // insert (&head);
    // dis(head);
    // delete (&head);
    // delete (&head);
    // dis(head);
    // delete (&head);
    // delete (&head);
    // delete (&head);
    // delete (&head);
    // delete (&head);
    // dis(head);
    // delete (&head);
    // dis(head);
    // dis(head);
    // insert(&head);
    // insert(&head);
    // dis(head);
    // delete (&head);
    // delete (&head);
    // dis(head);
    // insert(&head);
    // dis(head);

    int n;
    printf("1 for insertion.\n2 for deletion.\n3 for display.\n4 for displaying in reverse oreder.\n-1 to exit.\n");
    while (1)
    {
        printf("Enter choice: ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            insert(&head);
            break;
        case 2:
            delete (&head);
            break;
        case 3:
            dis(head);
            break;
        case 4:
            disback(head);
            break;
        default:
            if(n==-1)
                exit(0);
            printf("Wrong Choice!\n");
        }
    }
    
}