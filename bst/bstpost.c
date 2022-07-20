#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *right, *left;
};

struct Node *createnode(int d)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = d;
    temp->right = temp->left = NULL;
    return temp;
}

struct Node* createtreeutil(int post[], int* postind, int key, int min, int max, int size)
{
    if (*postind < 0)
        return NULL;

    struct Node *root = NULL;

    if (key > min && key < max)
    {
        root = createnode(key);
        *postind = *postind - 1;
        if (*postind >= 0)
        {
            root->right = createtreeutil(post, postind, post[*postind], key, max, size);
            root->left = createtreeutil(post, postind, post[*postind], min, key, size);
        }
    }
    return root;
}

struct Node* createtree(int post[], int size)
{
    int ind = size - 1;
    return createtreeutil(post, &ind, post[ind], INT_MIN, INT_MAX, size);
}

void inorder(struct Node* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void main()
{
    int post[] = {1, 7, 5, 50, 40, 10};
    int len = sizeof(post) / sizeof(post[0]);
    struct Node *root = createtree(post, len);

    inorder(root);
}