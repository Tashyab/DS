#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *right, *left;
};

struct Node* createnode(int d)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->data = d;
    new->right = new->left = NULL;
    return new;
}

struct Node* insert(struct Node** root, int d)
{
    if(*root==NULL)
        return createnode(d);

    (*root)->left = insert(&(*root)->left, d);
    (*root)->right = insert(&(*root)->right, d);

    return *root;
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
    struct Node *root = NULL;
    root = insert(&root, 10);
    insert(&root, 12);
    insert(&root, 14);
    insert(&root, 16);
    insert(&root, 18);
    insert(&root, 20);
    insert(&root, 22);

    inorder(root);
}
