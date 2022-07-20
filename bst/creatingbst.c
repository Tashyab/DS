#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

int height(struct Node *root)
{
    if (root == NULL)
        return 0;
    int lheight = height(root->left);
    int rheight = height(root->right);
    return lheight > rheight ? lheight + 1 : rheight + 1;
}

struct Node *createnode(int k)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->left = new->right = NULL;
    new->data = k;
    return new;
}

struct Node *search(struct Node *root, int key)
{
    struct Node *temp = root;
    while (temp != NULL)
    {
        if (key == temp->data)
            return temp;
        else if (key < temp->data)
            return search(root->left, key);
        else if (key > temp->data)
            return search(temp->right, key);
    }
    printf("%d is not present.\n", key);
    return NULL;
}

struct Node *insert(struct Node *root, int d)
{
    if (root == NULL)
    {
        return createnode(d);
    }
    if (d < root->data)
        root->left = insert((root->left), d);
    else if (d > root->data)
        root->right = insert((root->right), d);

    return root;
}

struct Node *inorederSucc(struct Node *root)
{
    struct Node *t = root;
    while (t && t->left != NULL)
    {
        t = t->left;
    }
    return t;
}

struct Node *inorederPre(struct Node *root)
{
    struct Node *t = root;
    while (t && t->right != NULL)
    {
        t = t->right;
    }
    return t;
}

struct Node *delete (struct Node *root, int key)
{
    if (root == NULL)
    {
        printf("Tree empty.\n");
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }
    if (key < root->data)
        root->left = delete (root->left, key);
    else if (key > root->data)
        root->right = delete (root->right, key);
    else
    {
        if (height(root->left) > height(root->right))
        {
            struct Node *t = inorederPre(root->left);
            root->data = t->data;
            root->left = delete (root->left, t->data);
        }
        else
        {
            struct Node *t = inorederSucc(root->right);
            root->data = t->data;
            root->right = delete (root->right, t->data);
        }
    }
    return root;
}

void inorder_display(struct Node *root)
{
    if (root != NULL)
    {
        inorder_display(root->left);
        printf("%d ", root->data);
        inorder_display(root->right);
    }
}

void presentlevel(struct Node *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1)
    {
        presentlevel(root->left, level - 1);
        presentlevel(root->right, level - 1);
    }
}

void displaybst_levelorder(struct Node *root)
{
    int h = height(root);
    for (int i = 1; i <= h; i++)
        presentlevel(root, i);
}

void main()
{
    // int arr[] = {11, 2, 4, 9, 1, 8};
    // int len = sizeof(arr) / sizeof(arr[0]);
    // struct Node *head = NULL;
    // head = insert(head, arr[0]);
    // for (int i = 1; i < len; i++)
    // {
    //     insert(head, arr[i]);
    // }
    // inorder_display(head);
    // printf("\n");

    // int key;
    // printf("Enter element to insert: ");
    // scanf("%d", &key);
    // insert(head, key);
    // inorder_display(head);

    // printf("\n");
    // printf("Enter element to search: ");
    // scanf("%d", &key);
    // struct Node *se = search(head, key);
    // if (se)
    //     printf("%d is found.\n", se->data);

    // inorder_display(head);
    // printf("\n");

    // printf("Enter element to delete: ");
    // scanf("%d", &key);
    // head = delete (head, key);
    // inorder_display(head);

    struct Node *root = NULL;
    root = insert(root, 10);
    insert(root, 12);
    insert(root, 14);
    insert(root, 9);
    insert(root, 11);
    insert(root, 13);
    delete (root, 12);
    inorder_display(root);
}