#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    int height;
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

struct Node *createnode(int d)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->data = d;
    new->left = new->right = NULL;
    new->height = height(new);
    return new;
}

int balanceFactor(struct Node *root)
{
    if (root == NULL)
        return 0;

    return height(root->left) - height(root->right);
}

struct Node *LLrotation(struct Node **root, struct Node *p)
{
    struct Node *pl = p->left;
    struct Node *plr = pl->right;

    pl->right = p;
    p->left = plr;

    p->height = height(p);
    pl->height = height(pl);
    
    if(*root == p)
        *root = pl;

    return pl;
}

struct Node *LRrotation(struct Node **root, struct Node *p)
{
    struct Node *pl = p->left;
    struct Node *plr = pl->right;

    pl->right = plr->left;
    p->left = plr->right;

    plr->left = pl;
    plr->right = p;

    p->height = height(p);
    pl->height = height(pl);
    plr->height = height(plr);

    if(*root == p)
        *root = plr;

    return plr;
}

struct Node *RLrotation(struct Node **root, struct Node *p)
{
    struct Node *pr = p->right;
    struct Node *prl = pr->left;

    p->right = prl->left;
    pr->left = prl->right;

    prl->left = p;
    prl->right = pr;

    p->height = height(p);
    pr->height = height(pr);
    prl->height = height(prl);

    if(*root == p)
        *root = prl;

    return prl;
}

struct Node *RRrotation(struct Node **root, struct Node *p)
{
    struct Node *pr = p->right;
    struct Node *prl = pr->left;

    pr->left = p;
    p->right = prl;

    p->height = height(p);
    pr->height = height(pr);

    if(*root == p)
        *root = pr;

    return pr;
}

struct Node *insert(struct Node **root, int d)
{
    if (*root == NULL)
    {
        return createnode(d);
    }
    struct Node *p = *root;
    if (d < p->data)
    {
        p->left = insert(&(p->left), d);
    }
    else if (d > p->data)
    {
        p->right = insert(&(p->right), d);
    }
    p->height = height(p);

    if (balanceFactor(p) == 2 && balanceFactor(p->left) == 1)
        return LLrotation(root, p);
    else if (balanceFactor(p) == 2 && balanceFactor(p->left) == -1)
        return LRrotation(root, p);
    else if (balanceFactor(p) == -2 && balanceFactor(p->right) == 1)
        return RLrotation(root, p);
    else if (balanceFactor(p) == -2 && balanceFactor(p->right) == -1)
        return RRrotation(root, p);

    return p;
}

struct Node* inorderPre(struct Node* node)
{
    struct Node *t = node;
    while (t && t->right!=NULL)
    {
        t = t->right;
    }
    return t;
}

struct Node *inorderSucc(struct Node *node)
{
    struct Node *t = node;
    while (t && t->left != NULL)
    {
        t = t->left;
    }
    return t;
}

struct Node *delete (struct Node **root, int key)
{
    if (*root == NULL)
    {
        printf("Node is present.\n");
        return NULL;
    }
    struct Node *p = *root;
    if (p->left == NULL && p->right == NULL)
    {
        if(*root == p)
            *root = NULL;
        free(p);
        return NULL;
    }
    if (key < p->data)
        p->left = delete (&(p->left), key);
    else if (key > p->data)
        p->right = delete (&(p->right), key);
    else
    {
        if (height(p->left) > height(p->right))
        {
            struct Node *t = inorderPre(p->left);
            p->data = t->data;
            p->left = delete (&(p->left), t->data);
        }
        else
        {
            struct Node *t = inorderSucc(p->right);
            p->data = t->data;
            p->right = delete (&(p->right), t->data);
        }
    }

    if (balanceFactor(p) == 2 && balanceFactor(p->left) == 1)
        return LLrotation(root, p);
    else if (balanceFactor(p) == 2 && balanceFactor(p->left) == -1)
        return LRrotation(root, p);
    else if (balanceFactor(p) == 2 && balanceFactor(p->left) == 0)
        return LRrotation(root, p);
    else if (balanceFactor(p) == -2 && balanceFactor(p->right) == 1)
        return RLrotation(root, p);
    else if (balanceFactor(p) == -2 && balanceFactor(p->right) == 0)
        return RLrotation(root, p);
    else if (balanceFactor(p) == -2 && balanceFactor(p->right) == -1)
        return RRrotation(root, p);

    return p;
}

void currentLevel(struct Node* root, int level)
{
    if (root==NULL)
    {
        return;
    }
    if(level == 1)
        printf("%d ", root->data);
    else if (level > 1)
    {
        currentLevel(root->left, level - 1);
        currentLevel(root->right, level - 1);
    }
}

void levelOrder(struct Node* root)
{
    int h = height(root);
    for (int i = 0; i <= h; i++)
        currentLevel(root, i);
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
    insert(&root, 9);
    insert(&root, 11);
    insert(&root, 13);
    delete (&root, 12);
    insert(&root, 16);
    delete (&root, 10);
    levelOrder(root);
}