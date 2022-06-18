#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int top;
    int last;
    int arr[5];
    struct Node *next;
};

struct Queue
{
    struct Node *first, *last;
    int size;
};

int isEmpty(struct Queue *queue)
{
    if (queue == NULL)
        return 1;
    else
        return 0;
}

void mixenq(struct Queue **queue, int num)
{

    if (isEmpty(*queue))
    {
        struct Queue *newQueue = (struct Queue *)malloc(sizeof(struct Queue));
        newQueue->first = (struct Node *)malloc(sizeof(struct Node));
        newQueue->first->top = -1;
        newQueue->first->last = 0;
        newQueue->size=1;
        newQueue->first->next = NULL;
        newQueue->last = newQueue->first;
        newQueue->last->arr[++newQueue->last->top] = num;
        *queue = newQueue;
        printf("Your data is enqueued.\n");
        return;
    }

    (*queue)->size++;

    if ((*queue)->last->top >= 4 && (*queue)->last->next == (*queue)->first)
    {
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        temp->top = 0;
        temp->arr[(temp->top)] = num;
        temp->next = NULL;
        (*queue)->last->next = temp;
        (*queue)->last = temp;
        (*queue)->last = (*queue)->first;
        printf("Your data is enqueued.\n");
        return;
    }
    else
    {
        (*queue)->last->arr[++((*queue)->last->top)] = num;
        printf("Your data is enqueued.\n");
        return;
    }
}

void mixdeq(struct Queue **queue)
{

    if (isEmpty(*queue))
    {
        printf("Empty Queue\n");
        return;
    }
    if ((*queue)->first->last >= (*queue)->first->top)
    {
        struct Node *temp = (*queue)->first;
        (*queue)->first = (*queue)->first->next;
        if ((*queue)->first == NULL)
            (*queue) = NULL;
        printf("Your data is dequeued.\n");
        free(temp);
        return;
    }
    else
    {
        printf("Your data is dequeued.\n");
        (*queue)->size--;
        ((*queue)->first->last)++;
    }
}

void display(struct Queue *queue)
{
    if (isEmpty(queue))
        printf("Empty Queue");

    while (!isEmpty(queue))
    {
        printf("%d ", queue->first->arr[queue->first->last]);
        mixdeq(&queue);
    }
}

int size(struct Queue* t)
{
    if(t==NULL)
        return 0;
    return t->size;
}

int main()
{
    struct Queue *queue = NULL;
    mixenq(&queue, 5);
    printf("Size is %d\n", size(queue));
    mixenq(&queue, 4);
    printf("Size is %d\n", size(queue));
    mixenq(&queue, 3);
    printf("Size is %d\n", size(queue));
    mixenq(&queue, 2);
    printf("Size is %d\n", size(queue));
    mixenq(&queue, 1);
    printf("Size is %d\n", size(queue));
    mixenq(&queue, 9);
    printf("Size is %d\n", size(queue));
    mixenq(&queue, 8);
    printf("Size is %d\n", size(queue));
    mixdeq(&queue);
    printf("Size is %d\n", size(queue));
    mixdeq(&queue);
    printf("Size is %d\n", size(queue));
    mixdeq(&queue);
    printf("Size is %d\n", size(queue));
    display(queue);
    return 0;
}