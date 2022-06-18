#include <stdio.h>
#include <stdlib.h>

struct QNode {
	int key;
	struct QNode* next;
};

struct Queue {
	struct QNode *front, *rear;

    int size;
};

struct QNode* newNode(int k)
{
	struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode));
	temp->key = k;
	temp->next = NULL;
	return temp;
}

struct Queue* createQueue()
{
	struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
	q->front = q->rear = NULL;
    q->size=0;
	return q;
}

void enQueue(struct Queue* q, int k)
{
	struct QNode* temp = newNode(k);

	if (q->rear == NULL) 
    {
        q->size++;
		q->front = q->rear = temp;
		return;
	}

	q->rear->next = temp;
	q->rear = temp;
    q->size++;
}

void deQueue(struct Queue* q)
{
	if (q->front == NULL)
		return;

	struct QNode* temp = q->front;

	q->front = q->front->next;

	if (q->front == NULL)
		q->rear = NULL;
    q->size--;
	free(temp);
}

int sizeOfQueue(struct Queue* q)
{
    return q->size;
}

int main()
{
	struct Queue* q = createQueue();
    printf("Size is %d\n",sizeOfQueue(q));
	enQueue(q, 10);
    printf("Size is %d\n",sizeOfQueue(q));
	enQueue(q, 20);
    printf("Size is %d\n",sizeOfQueue(q));
	deQueue(q);
	printf("Size is %d\n",sizeOfQueue(q));
	deQueue(q);
    printf("Size is %d\n",sizeOfQueue(q));
	enQueue(q, 30);
	printf("Size is %d\n",sizeOfQueue(q));
	enQueue(q, 40);
	printf("Size is %d\n",sizeOfQueue(q));
	enQueue(q, 50);
    printf("Size is %d\n",sizeOfQueue(q));
	deQueue(q);
	printf("Queue Front : %d \n", q->front->key);
	printf("Queue Rear : %d", q->rear->key);
	return 0;
}
