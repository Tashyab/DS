#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int d;
    struct Node *left, *right;
};

struct Snode
{
    struct Node *addr;
    struct Snode *next;
};

void push(struct Snode** top, struct Node *d)
{
    struct Snode *t = malloc(sizeof(struct Snode));
    t->addr = d;
    t->next = *top;
    *top = t;
}

struct Node* pop(struct Snode** top)
{
    if(!top)
        return NULL;
    struct Node *t;
    struct Snode *p = *top;
    p->addr = t;
    (*top) = (*top)->next;
    free(p);
    return t;
}

void main()
{

}