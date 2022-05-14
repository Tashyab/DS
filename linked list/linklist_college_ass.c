#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
}*first=NULL;

void createllist(int arr[], int l)
{
    struct Node *t, *last;
    first = (struct Node*) malloc(sizeof(struct Node));
    first->data=arr[0]; 
    first->next=NULL;
    last=first;
    

    for(int i=1; i<l; i++)
    {
        t=(struct Node*) malloc(sizeof(struct Node));
        t->data=arr[i]; 
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void reversal()
{
    struct Node *prev=NULL, *current=first, *next=NULL;
    while(current !=NULL)
    {
        next=prev;
        prev=current;
        current=current->next;
        prev->next=next;
    }
    first=prev;
}

void disp(int index, int k)
{
    int i=1, j=0;
    struct Node *p=first;
    while(p!=NULL)
    { 
        if(i==index)
        {
            printf("%d ", p->data);
            j++;
            if(j==k)
                break;
        }
        else
            i++;
        p=p->next;
    }
}


void insertion(int d, int in)
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

void deletion(int in)
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

void show()
{
    printf("\n");
    struct Node *t=first;
    while(t!=0)
    {
        printf("%d ", t->data);
        t=t->next;
    }
    printf("\n");
}

void main()
{
	int arr[]={5, 4, 3, 2, 1, 0};
	createllist(arr, 6);
    show();
	reversal();
    printf("After Reversal-");
    show();
	int ind;
	int k;
	printf("Enter 1, 2 or 3 to delete, insert or display: ");
	int n;
	scanf("%d", &n);
	switch(n)
	{
		case 1:
			{
				printf("Enter index to start from: ");
				scanf("%d", &ind);
				printf("Enter the number of elements to delete: ");
				scanf("%d", &k);
				for (int i = 0; i < k; i++)
                {
                    deletion(ind);
                }
                printf("After deletion the list looks like-");
                show();
			}
            break;

		case 2:
			{
				printf("Enter index to insert after: ");
				scanf("%d", &ind);
				printf("Enter the number of elements to insert: ");
				scanf("%d", &k);
                int *arr=malloc(k*sizeof(int));
                for (int i = 0; i < k; i++)
                {
                    printf("Enter element %d: ", i+1);
                    scanf("%d", &arr[i]);
                }
				for(int i=0; i<k; i++)
                {
                    insertion(arr[i], ind);
                    ind++;
                }
                printf("After insertion the list looks like-");
                show();
			}
            break;

		case 3:
			{
				
				printf("Enter index to display after: ");
				scanf("%d", &ind);
				printf("Enter the number of elements to display: ");
				scanf("%d", &k);
				disp(ind, k);
			}
            break;
        default: printf("Wrong input");
	}
}
