#include <stdio.h>
#include <stdlib.h>

int sum = 0, min=1000;
struct Node
{
    int data;
    struct Node *right;
    struct Node *left;
    int streesum;
};
struct Node *comp = NULL, *temp;

struct Qnode
{
    struct Node *data;
    struct Qnode *next;
} * head, *rear;

struct Qnode *createhead(struct Qnode **head, struct Qnode **rear, struct Node *d)
{
    *head = (struct Qnode *)malloc(sizeof(struct Qnode));
    (*head)->next = NULL;
    (*head)->data = d;
    (*rear) = (*head);
}

void enq(struct Qnode **head, struct Qnode **rear, struct Node *d)
{
    if (*head == NULL)
    {
        createhead(head, rear, d);
        return;
    }
    struct Qnode *new = (struct Qnode *)malloc(sizeof(struct Qnode));
    (*rear)->next = new;
    new->next = NULL;
    new->data = d;
    (*rear) = new;
}

struct Node *deq(struct Qnode **head)
{
    if (*head == NULL)
        return NULL;
    struct Qnode *p = *head;
    *head = (*head)->next;
    struct Node *x = p->data;
    free(p);
    return x;
}

struct Node *createNode(int d)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = d;
    t->right = NULL;
    t->left = NULL;
    return t;
}

int search(int arr[], int strt, int end, int value)
{
    int i = 0;
    for (i = strt; i <= end; i++)
    {
        if (arr[i] == value)
            break;
    }
    return i;
}

void isPresent(struct Node *curr, int key, int *flag)
{
    if (curr == NULL)
    {
        return;
    }
    if (curr->data == key)
    {
        *flag = 1;
    }
    isPresent(curr->left, key, flag);
    isPresent(curr->right, key, flag);
}

struct Node *buildutil(int in[], int post[], int inStrt, int inEnd, int *pindex)
{
    if (inStrt > inEnd)
        return NULL;

    struct Node *cur_root = createNode(post[*pindex]);
    (*pindex)--;

    if (inStrt == inEnd)
        return cur_root;

    int ind = search(in, inStrt, inEnd, cur_root->data);

    cur_root->right = buildutil(in, post, ind + 1, inEnd, pindex);
    cur_root->left = buildutil(in, post, inStrt, ind - 1, pindex);

    return cur_root;
}

struct Node *buildtree(int in[], int post[], int n)
{
    int pindex = n - 1;
    return buildutil(in, post, 0, n - 1, &pindex);
}

int nsum(struct Node *node)
{
    if (node == NULL)
        return 0;
    node->streesum = node->data + nsum(node->left) + nsum(node->right);
    return node->streesum;
}

struct Node *findNode(struct Node *node, int nodeval)
{
    if (node == NULL)
        return NULL;

    if (nodeval == node->data)
    {
        return node;
    }

    struct Node *left = findNode(node->left, nodeval);
    if (left)
        return left;

    return findNode(node->right, nodeval);
}

void insertNode(struct Node *rt, int d)
{
    if (rt == NULL)
    {
        rt = createNode(d);
        return;
    }

    enq(&head, &rear, rt);
    while (head != NULL)
    {
        struct Node *temp = deq(&head);
        if (temp->left != NULL)
            enq(&head, &rear, temp);
        else
        {
            temp->left = createNode(d);
            return;
        }
        if (temp->right != NULL)
            enq(&head, &rear, temp);
        else
        {
            temp->right = createNode(d);
            return;
        }
    }
}

void insertChild(struct Node *t, int k1, int k2)
{
    if (findNode(t, k1) == NULL)
    {
        if (findNode(t, k2) != NULL)
        {
            struct Node *node = findNode(t, k2);
            if (node->left == NULL)
            {
                insertNode(node, k1);
                nsum(t);
                return;
            }
            if (node->right == NULL)
            {
                insertNode(node, k1);
                nsum(t);
                return;
            }
            if (node->left->streesum <= node->right->streesum)
            {
                insertNode(node->left, k1);
            }
            else
            {
                insertNode(node->right, k1);
            }
        }
        else
        {
            printf("Error:Both nodes not present!");
            return;
        }
    }
    nsum(t);
}

void swap(struct Node **n1, struct Node **n2)
{
    int temp = (*n1)->data;
    (*n1)->data = (*n2)->data;
    (*n2)->data = temp;
}

void deleteLeaf(struct Node **root, int *key, int *flag)
{
    if (*root == NULL || *flag == 1)
    {
        return;
    }
    if ((*root)->left == NULL && (*root)->right == NULL)
    {
        *flag = 1;
        *key = (*root)->data;
        *root = NULL;
        return;
    }
    deleteLeaf (&((*root)->left), key, flag);
    deleteLeaf (&((*root)->right), key, flag);
}

void deleteNode_logic(struct Node **root, int key)
{
    if (*root == NULL)
        return;
    if ((*root)->data == key)
    {
        int flag = 0;
        int replacementKey;
        if ((*root)->left == NULL && (*root)->right == NULL)
        {
            *root = NULL;
            return;
        }
        else if ((*root)->left != NULL && (*root)->right != NULL)
        {
            if (((*root)->left->streesum) - ((*root)->right->streesum) > 0)
            {
                deleteLeaf(&((*root)->left), &replacementKey, &flag);
            }
            else
            {
                deleteLeaf(&((*root)->right), &replacementKey, &flag);
            }
        }
        else
        {
            if ((*root)->left == NULL)
            {
                deleteLeaf(&((*root)->right), &replacementKey, &flag);
            }
            else if ((*root)->right == NULL)
            {
                deleteLeaf(&((*root)->left), &replacementKey, &flag);
            }
        }
        (*root)->data = replacementKey;
    }
    deleteNode_logic(&((*root)->left), key);
    deleteNode_logic(&((*root)->right), key);
}

void deleteNode(struct Node *root, int key)
{
    int flag = 0;
    isPresent(root, key, &flag);
    if (flag == 0)
    {
        printf("Node not present.\n");
        return;
    }
    deleteNode_logic(&root, key);
}

void display(struct Node *t)
{
    if (t == NULL)
        return;

    printf("%d ", t->data);
    display(t->left);
    display(t->right);
}

void searchp(int i, struct Node *root)
{

    if (root == NULL)
    {
        return;
    }

    searchp(i, root->left);
    searchp(i, root->right);
    if (root->data == i)
    {
        comp = root;
    }
}

void print2DUtil(struct Node *root, int space)
{

    if (root == NULL)
        return;

    space += 10;

    print2DUtil(root->right, space);

    printf("\n");
    if (root->data != 0)
    {
        for (int i = 10; i < space; i++)
            printf("-");
    }
    if (root->data != 0)
    {
        printf("%d-->sum[%d]\n", root->data, root->streesum);
    }

    print2DUtil(root->left, space);
}

void print2D(struct Node *root)
{
    print2DUtil(root, 0);
}

void streesum(struct Node *root)
{
    struct Node *ptr = root;
    if (ptr == NULL)
    {
        return;
    }

    sum = sum + ptr->data;

    streesum(ptr->left);

    streesum(ptr->right);
}

void makesum(struct Node *root)
{
    sum = 0;
    struct Node *ptr = root;
    if (ptr == NULL)
    {
        return;
    }
    streesum(ptr);
    ptr->streesum = sum;

    makesum(ptr->left);

    makesum(ptr->right);
}

void insertLevelOrder(struct Node *root, int key)
{
    struct Node *ptr = root;
    if (ptr->left == NULL)
    {
        ptr->left = createNode(key);
        return;
    }
    else if (ptr->right == NULL)
    {
        ptr->right = createNode(key);
        return;
    }
    else if (ptr->left->left == NULL || ptr->left->right == NULL)
    {
        ptr = ptr->left;
        insertLevelOrder(ptr, key);
        return;
    }
    else
    {
        if (ptr->right->left == NULL || ptr->right->right == NULL)
        {
            ptr = ptr->right;
            insertLevelOrder(ptr, key);
            return;
        }
    }
}

int find_diff(struct Node *root)
{

    if (root->left == NULL && root->right == NULL)
    {
        return root->data;
    }
    else if (root->right == NULL)
    {
        return root->left->streesum;
    }
    else if (root->left == NULL)
    {
        return -root->right->streesum;
    }

    return root->left->streesum - root->right->streesum;
}

void find_min(struct Node *root)
{
    struct Node *ptr = root;
    if (ptr->left == NULL && ptr->right == NULL)
    {

        return;
    }

    int k = find_diff(ptr);

    if (min > k)
    {
        min = k;

        temp = ptr;
    }
    if (ptr->left != NULL)
    {
        find_min(ptr->left);
    }

    if (ptr->right != NULL)
    {
        find_min(ptr->right);
    }
}

void merge(struct Node *root, struct Node *root1)
{

    find_min(root);
    printf("\n alpha %d ", min);
    struct Node *ptr = temp;
    if (ptr->left->streesum < ptr->right->streesum)
    {
        while (ptr->left != NULL)
        {
            ptr = ptr->left;
        }
        ptr->left = root1;
        makesum(root);
    }
    else
    {
        while (ptr->right != NULL)
        {
            ptr = ptr->right;
        }
        ptr->right = root1;
        makesum(root);
    }
}

int main()
{
    int n;
    head = NULL;
    rear = NULL;
    printf("Enter the number of nodes in the tree: ");
    scanf("%d", &n);
    int in[n];
    int post[n];
    printf("Enter the inorder traversal-\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &in[i]);

    printf("Enter the postorder traversal-\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &post[i]);

    struct Node *root = buildtree(in, post, n);
    printf("The preorder traversal of the tree is- ");
    display(root);

    int ns;
    printf("\nEnter the node value below which you want to find the sum: ");
    scanf("%d", &ns);
    nsum(root); // calling this function to find the tree sum for every node and store it in the streesum
    printf("The sum is %d\n", findNode(root, ns)->streesum);

    int k1, k2;
    printf("Enter the value for key 1: ");
    scanf("%d", &k1);
    printf("Enter the value for key 2: ");
    scanf("%d", &k2);
    insertChild(root, k1, k2);
    printf("The new order with the preorder traversal is: ");
    display(root);

    int k;
    printf("\n");
    printf("Enter the key value to delete: ");
    scanf("%d", &k);
    deleteNode(root, k);
    display(root);\

    //4
    struct Node *rt = buildtree(in, post, n);
    int key1, key2;
    printf("\n Enter key1: ");
    scanf("%d", &key1);
    printf("\n Enter key2: ");
    scanf("%d", &key2);
    searchp(key2, root);
    int i;
    int arr[7];
    if (comp == NULL)
    {
        arr[0] = key2;
        arr[1] = key1;
        i = 2;
        comp = NULL;
    }
    else
    {
        printf("KEY 2 is found, value:%d\n", key2);
        i = 0;
        comp = NULL;
    }

    while (i < 7)
    {
        printf("Enter key1: ");
        scanf("%d", &key1);
        printf("Enter key2: ");
        scanf("%d", &key2);
        searchp(key2, root);
        if (comp == NULL)
        {
            arr[i] = key1;
            i++;
        }
        else
        {
            printf("Key2 is present.\n");
            comp = NULL;
        }
    }
    int j = 1;
    struct Node *root1 = createNode(arr[0]);
    while (j < 7)
    {
        insertLevelOrder(root1, arr[j]);
        j++;
    }
    printf("Tree 1: \n");
    makesum(root1);
    print2D(root1);
    merge(root, root1);
    printf("\n\n\n");
    printf("Tree After merging is:\n");
    print2D(root);
}