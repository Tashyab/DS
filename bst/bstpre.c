#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createnode(int d)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->data = d;
    new->left = new->right = NULL;
    return new;
}

struct Node* createtreeutil(int pre[], int* preindex, int low, int high, int size)
{
    if(*preindex >=  size || low > high)
        return NULL;

    struct Node *root = createnode(pre[*preindex]);
    *preindex = *preindex + 1;

    if (low==high)
        return root;

    int i;
    for (i = low; i <= high; i++)
        if(pre[i] > root->data)
            break;

    root->left = createtreeutil(pre, preindex, *preindex, i - 1, size);
    root->right = createtreeutil(pre, preindex, i, high, size);

    return root;
}

struct Node* constructTree(int pre[], int size)
{
    int preindex = 0;
    return createtreeutil(pre, &preindex, 0, size - 1, size);
}

void printInorder(struct Node* root)
{
    if(root!=NULL)
    {
        printInorder(root->left);
        printf("%d ", root->data);
        printInorder(root->right);
    }
}

void main()
{
    int pre[] = {10, 5, 1, 7, 40, 50};
    int size = sizeof(pre) / sizeof(pre[0]);

    struct Node *root = constructTree(pre, size);
    
    printInorder(root);
}