#include <stdio.h>
#include <stdlib.h>
int col1 = 0;
int col2 = 0;

int isPrime(int n)
{
    for (int i = 2; i <= n/2; i++)
    {
        if(n==1 || n==0 || n%i==0)
            return 0;
    }
    return 1;
}

struct Node
{
    int data;
    struct Node *next;
};

void createhead(struct Node* table1[], struct Node **head, int d, int key)
{
    *head = (struct Node *)malloc(sizeof(struct Node));
    (*head)->next = NULL;
    (*head)->data = d;
    table1[key] = *head;
}

void insertll(struct Node* table1[], int key, struct Node **head, int d)
{
    if(*head==NULL)
    {
        createhead(table1, head, d, key);
        printf("%d inserted.\n", d);
        return;
    }

    struct Node *t = *head;
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->data = d;

    if(d<t->data)
    {
        new->next = *head;
        *head = new;
        table1[key] = *head;
        col1++;
        printf("Collision occurred, %d inserted.\n", d);
        return;
    }

    while(d>t->data)
    {
        if(t->next==NULL)
            break;
        t = t->next;
    }
    new->next = t->next;
    t->next = new;
    col1++;
    
    printf("Collision occurred, %d is inserted.\n", d);
}

void displayll(struct Node* arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        struct Node *t = arr[i];
        if(i<10)
            printf("0%d |", i);
        else
            printf("%d |", i);
        while(t!=NULL)
        {
            printf("%d->", t->data);
            t = t->next;
        }
        printf("NULL\n");
    }
}

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if(arr[i]!=-1)
            if(i<10)
                printf("0%d | %d\n", i, arr[i]);
            else
                printf("%d | %d\n", i, arr[i]);
        else
            printf("%d | <E>\n", i);
    }
}

void main()
{
    entersize:
    int tsize;
    printf("Enter a prime number for table size: ");
    scanf("%d", &tsize);
    if(isPrime(tsize)==0)
    {
        printf("Not a valid prime number, Enter again!\n");
        goto entersize;
    }
    printf("-----------------------------------------------\n");
    printf("-----------------------------------------------\n");
    int randarr[tsize];
    for (int i = 0; i < tsize; i++)
    {
        randarr[i] = rand() % 1000;
    }

    // Table 1
    struct Node* table1[tsize];
    for (int i = 0; i < tsize; i++)
        table1[i] = NULL;

    for (int i = 0; i < tsize; i++)
    {
        int n = randarr[i];
        int key = n % tsize; // hash function
        struct Node* head = table1[key];
        insertll(table1, key, &head, n);
    }
    printf("-----------------------------------------------\n");
    printf("-----------------------------------------------\n");

    displayll(table1, tsize);
    printf("Total number of collisions in Table 1 is %d.\n", col1);
    printf("\n");

    //Table 2
    int table2[tsize];
    for (int i = 0; i < tsize; i++)
        table2[i] = -1;
    
    for (int i = 0; i < tsize; i++) // Ideally we take i<tsize/2 to maintain value of loading factor <= 0.5
    {
        int n = randarr[i];
        int key;
        for (int i = 0; i < tsize; i++)
        {
            key = (n % tsize + i) % tsize; //hash function
            if(i>0)
                col2++;
            if(table2[key]==-1)
            {
                table2[key] = n;
                break;
            }
        }
    }
    display(table2, tsize);
    printf("Total number of collisions in Table 2 is %d.\n", col2);
}