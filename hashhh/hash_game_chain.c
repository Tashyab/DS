#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

void insertsum(struct Node *head, int d)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    struct Node *t = head;
    while (t)
    {
        if (t->next == NULL)
            break;
        t = t->next;
    }
    new->data = d + t->data;
    t->next = new;
    new->prev = t;
    new->next = NULL;
}

void displayll(struct Node *arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("NULL<-->");
        struct Node *t = arr[i];
        while (t != NULL)
        {
            printf("%d<-->", t->data);
            t = t->next;
        }
        printf("NULL\n");
    }
}

void findwinner(struct Node *arr[], int n, int a[], int key)
{
    int win = 0;
    for (int i = 0; i < n; i++)
    {
        struct Node *t = arr[i];
        int j = 0;
        while (t != NULL)
        {
            if (t->data == key)
            {
                win = 1;
                printf("{");
                for (int k = i; k <= i + j; k++)
                {
                    if (k != i + j)
                        printf("%d,", a[k]);
                    else
                        printf("%d", a[k]);
                }
                printf("}\n");
                break;
            }
            j++;
            t = t->next;
        }
        if (win == 1)
            break;
    }
    if (win == 1)
        printf("B is the winner.");
    else
        printf("Haha, %d is not there.\nA is the winner.", key);
}

void main()
{
    int asize;
    printf("Enter the size of array A: ");
    scanf("%d", &asize);
    int a[asize];
    printf("Enter the array: ");
    for (int i = 0; i < asize; i++)
    {
        int n;
        scanf("%d", &n);
        a[i] = n;
    }

    struct Node *tablea[asize];
    for (int i = 0; i < asize; i++)
    {
        struct Node *head = (struct Node *)malloc(sizeof(struct Node));
        head->data = a[i];
        head->next = head->prev = NULL;
        tablea[i] = head;
        for (int j = i + 1; j < asize; j++)
        {
            insertsum(head, a[j]);
        }
    }
    // displayll(tablea, asize);
    // printf("--------------------------------------------------\n");
    // printf("--------------------------------------------------\n");

    int b;
    printf("Enter value B (value to be found): ");
    scanf("%d", &b);
    findwinner(tablea, asize, a, b);
    printf("\n");
    printf("The number of collisions in the Table is %d.", asize);
}