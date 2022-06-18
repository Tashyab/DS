#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int front;
    int rear;
    int *arr;
};
struct queue *q;

int isEm()
{
    if (q->front == q->rear || (q->rear == -1 && q->front == q->size - 1))
        return printf("Queue is Empty\n");
    else
        return 0;
}

int isF_rear()
{
    if (q->rear == q->front || (q->front == -1 && q->rear == q->size - 1))
        return printf("Queue is full\n");
    else
        return 0;
}

int isF_front()
{
    if (q->rear == q->front || (q->rear == -1 && q->front == -1))
        return printf("Queue is full\n");
    else
        return 0;
}

void stretchDeq()
{
    int temp = q->size - 1;
    q->size += 5;

    for (int i = temp; i >= q->front; i--)
    {
        q->arr[i + 5] = q->arr[i];
    }
    q->front = q->front + 5;
}

void reduceDeq()
{
    int temp = q->size;

    for (int i = q->front; i <= temp; i++)
    {
        q->arr[i + 1 - 5] = q->arr[i + 1];
    }
    q->front = q->front - 5;
    q->size -= 5;
}

void insertR()
{
    if (q->front == -1 && q->rear == -1)
    {
        q->rear = 0;
        printf("Enter the data: ");
        scanf("%d", &q->arr[q->rear]);
    }
    else if (isF_rear() == 0)
    {
        q->rear = (q->rear + 1) % q->size;
        printf("Enter the data: ");
        scanf("%d", &q->arr[q->rear]);
    }
}

void insertF()
{

    if (q->front == -1)
    {
        q->front = q->size - 1;
    }

    printf("Enter the data: ");
    scanf("%d", &q->arr[q->front]);
    q->front = (q->front - 1) % q->size;
}

void deleteR()
{
    if (q->rear == -1)
        q->rear = q->size - 1;
    printf("\nDequeued element: %d", q->arr[q->rear]);
    q->rear = (q->rear - 1) % q->size;
}

void deleteF()
{

    q->front = (q->front + 1) % q->size;
    printf("\nDequeued element: %d", q->arr[q->front]);
}

void printEle()
{
    int ptr = q->front;
    printf("\nThe elements are:\n");
    if (q->rear == -1)
    {
        do
        {
            ptr = (ptr + 1) % q->size;
            printf("%d ", q->arr[ptr]);
        } while (ptr != q->size - 1);
        printf("\n");
    }
    else
    {
        do
        {
            ptr = (ptr + 1) % q->size;
            printf("%d ", q->arr[ptr]);
        } while (ptr != q->rear);
        printf("\n");
    }
}

int main()
{
    q = (struct queue *)malloc(sizeof(struct queue));
    q->size = 10;
    q->arr = (int *)malloc(100 * sizeof(int));
    q->front = q->rear = -1;

    int input, n;
    do
    {
        printf("\nEnter the operation to be performed\n");
        printf("\nInsert in Front: Enter 1\nInsert in Rear: Enter 2\nDelete in Front: Enter 3\nDelete in Rear: Enter 4\nExit: Enter 0.\n\n");
        printf("Enter your choice: ");
        scanf("%d", &input);

        switch (input)
        {
        case 1:
            printf("Enter the no. of elements to insert in front\n");
            scanf("%d", &n);

            if (n >= q->size)
            {
                q->size += 5;
            }

            insertF();
            for (int i = 1; i < n; i++)
            {
                if (isF_front() == 0)
                {
                    insertF();
                }
                else
                {
                    stretchDeq();
                    insertF();
                }
            }
            printEle();
            break;

        case 2:

            printf("Enter the no. of elements to insert in rear\n");
            scanf("%d", &n);

            if (n >= q->size)
            {
                q->size += 5;
            }
            insertR();
            for (int i = 1; i < n; i++)
            {
                if (isF_rear() != 0)
                    stretchDeq();
                insertR();
            }
            printEle();
            break;

        case 3:

            printf("Enter the no. of elements to delete in front\n");
            scanf("%d", &n);

            if (n > 5 && q->size > 10 || q->size > 10 && (q->front - q->rear) > 5)
            {
                reduceDeq();
            }

            for (int i = 0; i < n; i++)
            {
                if (isEm() == 0)
                {
                    deleteF();
                }
                else
                    break;
            }
            if (q->front == q->rear)
            {
                printf("\nThe elements are:\n");
                printf("\n");
            }
            else
                printEle();
            break;

        case 4:

            printf("Enter the no. of elements to delete in rear\n");
            scanf("%d", &n);

            if (n > 5 && q->size > 10 || q->size > 10 && (q->front - q->rear) > 5)
            {
                reduceDeq();
            }

            deleteR();
            for (int i = 1; i < n; i++)
            {
                if (isEm() == 0)
                {
                    deleteR();
                }
                else
                    break;
            }
            if (q->front == q->rear)
            {
                printf("\nThe elements are:\n");
                printf("\n");
            }
            else
                printEle();
            break;

        default:
            if (input != 0)
                printf("Wrong Choice.");
            break;
        }
    } while (input != 0);
    return 0;
}