#include <stdio.h>
#include <stdlib.h>
#define max 10

int sum = 0, min = 1000, f;
struct node
{
    int key;
    int streeSum;
    struct node *left;
    struct node *right;
};
struct node *comp = NULL, *temp;
struct node *newnode(int key)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->key = key;
    node->left = node->right = NULL;

    return node;
}
void inorderTraversal(struct node *root)
{

    if (root == NULL)
    {
        return;
    }

    inorderTraversal(root->left);
    printf("%d ", root->key);
    inorderTraversal(root->right);
}

void postorderTraversal(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->key);
}

struct node *construct(int inorder[], int start, int end, int postorder[], int *pIndex)
{

    if (start > end)
    {
        return NULL;
    }

    struct node *node = newnode(postorder[(*pIndex)--]);

    int i;
    for (i = start; i <= end; i++)
    {
        if (inorder[i] == node->key)
        {
            break;
        }
    }

    node->right = construct(inorder, i + 1, end, postorder, pIndex);

    node->left = construct(inorder, start, i - 1, postorder, pIndex);

    return node;
}

struct node *constructTree(int inorder[], int postorder[], int n)
{

    int *pIndex = &n;
    return construct(inorder, 0, n, postorder, pIndex);
}
void print2DUtil(struct node *root, int space)
{

    if (root == NULL)
        return;

    space += max;

    print2DUtil(root->right, space);

    printf("\n");
    if (root->key != 0)
    {
        for (int i = max; i < space; i++)
            printf("-");
    }
    if (root->key != 0)
    {
        printf("%d-->sum[%d]\n", root->key, root->streeSum);
    }

    print2DUtil(root->left, space);
}

void print2D(struct node *root)
{
    print2DUtil(root, 0);
}
void streesum(struct node *root)
{
    struct node *ptr = root;
    if (ptr == NULL)
    {
        return;
    }

    sum = sum + ptr->key;

    streesum(ptr->left);

    streesum(ptr->right);
}
void search(int i, struct node *root)
{

    if (root == NULL)
    {
        return;
    }

    search(i, root->left);
    search(i, root->right);
    if (root->key == i)
    {
        comp = root;
    }
}
void insetkey(struct node *root, int key1, int key2)
{
    int l, r;
    search(key2, root);
    if (comp == NULL)
    {
        printf("error NOT FOUND KEY2->[%D]", key2);
    }
    else
    {

        // struct node *ptr = comp;
        if (comp->left->streeSum < comp->right->streeSum)
        {
            struct node *ptr = comp->left, *s;
            s = newnode(key1);
            comp->left = s;
            s->left = ptr;
        }
        else
        {
            struct node *ptr = comp->right, *s;
            s = newnode(key1);
            comp->right = s;
            s->right = ptr;
        }
    }
}
void makesum(struct node *root)
{
    sum = 0;
    struct node *ptr = root;
    if (ptr == NULL)
    {
        return;
    }
    streesum(ptr);
    ptr->streeSum = sum;

    makesum(ptr->left);

    makesum(ptr->right);
}
void findleaf(struct node *root)
{

    if (root == NULL)
    {
        return;
    }

    if (root->left == NULL && root->right == NULL)
    {
        if (f < root->key)
        {
            f = root->key;
            printf("%d *\n", f);
        }
    }

    findleaf(root->left);

    findleaf(root->right);
}

void deletenode(int key, struct node *root)
{

    search(key, root);
    if (comp->left->streeSum > comp->right->streeSum)
    {
        int store = comp->key;
        struct node *ptr = comp->left, *m = comp;
        findleaf(ptr);
        m->key = f;
        search(f, ptr);
        comp->key = 0;
        makesum(root);
        comp = NULL;

        f = 0;
    }
    else
    {

        int store = comp->key;
        struct node *ptr = comp->right, *m = comp;
        findleaf(ptr);
        m->key = f;
        search(f, ptr);
        comp->key = 0;
        makesum(root);
        comp = NULL;

        f = 0;
    }
}
void insertLevelOrder(struct node *root, int key)
{
    struct node *ptr = root;
    if (ptr->left == NULL)
    {
        ptr->left = newnode(key);
        return;
    }
    else if (ptr->right == NULL)
    {
        ptr->right = newnode(key);
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
int find_diff(struct node *root)
{

    if (root->left == NULL && root->right == NULL)
    {
        return root->key;
    }
    else if (root->right == NULL)
    {
        return root->left->streeSum;
    }
    else if (root->left == NULL)
    {
        return -root->right->streeSum;
    }

    return root->left->streeSum - root->right->streeSum;
}
void find_min(struct node *root)
{
    struct node *ptr = root;
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
void merge(struct node *root, struct node *root1)
{

    find_min(root);
    printf("\n alpha %d ", min);
    struct node *ptr = temp;
    if (ptr->left->streeSum < ptr->right->streeSum)
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
    printf("ENTER  No. of Element :");
    scanf("%d", &n);
    int inorder[n];
    printf("\n \n Enter element of InodeR ");
    for (int i = 0; i < n; i++)
    {
        printf("\n enter  element :");
        scanf("%d", &inorder[i]);
    }

    int postorder[n];
    printf("\n \n Enter element of POSTODER ");

    for (int i = 0; i < n; i++)
    {
        printf("\n enter  element :");
        scanf("%d", &postorder[i]);
    }
    // int inorder[] = {7, 6, 8, 2, 1, 5, 3, 4};
    // int postorder[] = {7, 8, 6, 2, 5, 4, 3, 1};
    // int n = sizeof(inorder) / sizeof(inorder[0]);

    struct node *root = constructTree(inorder, postorder, n - 1);

    printf("\n Inorder traversal is \n ");
    inorderTraversal(root);
    printf("\nPostorder traversal is \n ");
    postorderTraversal(root);
    printf("\n\n\n");
    makesum(root);
    print2D(root);

    int k = 1;
    while (k > 0)
    {
        int key1, key2, key, arr[7];
        printf("\n\n\n");
        int p = 1;
        printf("##### PART--1 #####\n\n");
        while (p > 0)
        {
            printf("\n ENTER key sum you want to find :");
            scanf("%d", &key);

            comp = NULL;

            search(key, root);

            printf("SUM--> %d", comp->streeSum);
            comp = NULL;
            printf("\n PRESS 0 TO EXIT  PART-1:");
            scanf("%d", &p);
        }
        printf("\n\n##### PART--2 #####\n\n");
        printf("\n enter key1 and key2 :");
        scanf("%d %d", &key1, &key2);
        insetkey(root, key1, key2);
        makesum(root);
        print2D(root);

        printf("\n\n ##### PART-3: ######\n\n");
        int t = 0;
        printf("\n PRESS 1 TO delelte :");
        scanf("%d", &t);
        while (t > 0)
        {
            int key;
            printf("\nEnter the KEY you want to delete :");
            scanf("%d", &key);

            printf("\n####### after deletion ######");
            printf("\n\n\n");
            deletenode(key, root);
            makesum(root);
            print2D(root);
            comp = NULL;
            printf("\n PRESS 0 TO CLOSE PART-3 :");
            scanf("%d", &t);
        }
        printf("\n\n #####  PART-4: #####\n\n");
        printf("\n enter key1 and key2 :");
        scanf("%d %d", &key1, &key2);
        search(key2, root);
        int i;
        if (comp == NULL)
        {
            arr[0] = key2;
            arr[1] = key1;
            i = 2;
            comp = NULL;
        }
        else
        {
            printf(" KEY-2--> [ %d ] is  FOUNDed ", key2);
            i = 0;
            comp = NULL;
        }

        while (i < 7)
        {
            printf("\n enter key1 and key2 :");
            scanf("%d %d", &key1, &key2);
            search(key2, root);
            if (comp == NULL)
            {
                arr[i] = key1;
                i++;
            }
            else
            {
                printf("key2 is present ");
                comp = NULL;
            }
        }
        int j = 1;
        // int j = 2, arr[7] = {9, 10, 11, 12, 13, 14, 15};
        struct node *root1 = newnode(arr[0]);
        // struct node *root1 = newnode(arr[0]);
        while (j < 7)
        {
            insertLevelOrder(root1, arr[j]);
            j++;
        }
        printf("#### root1 tree ####");
        makesum(root1);
        print2D(root1);
        merge(root, root1);
        printf("\n\n\n");
        printf("\n\n ####  TREE after MERGING #### \n\n");
        print2D(root);
        printf("\n \n PRESS 0 TO EXIT ALL :");
        scanf("%d", &k);
    }

    return 0;
}