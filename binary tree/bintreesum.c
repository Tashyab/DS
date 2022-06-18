#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *right;
    struct Node *left;
};

struct Node* createNode(int d)
{
    struct Node* t=(struct Node*)malloc(sizeof(struct Node));
    t->data=d;
    t->right=NULL;
    t->left=NULL;
    return t;
}

int search(int arr[], int strt, int end, int value)
{
    int i=0;
    for (i = strt; i <= end; i++)
    {
        if(arr[i]==value)
            break;
    }
    return i;
}

struct Node* buildutil(int in[], int post[], int inStrt, int inEnd, int* pindex)
{
    if(inStrt> inEnd)
        return NULL;

    struct Node* node=createNode(post[*pindex]);
    (*pindex)--;
    
    int ind=search(in, inStrt, inEnd, node->data);

    node->right=buildutil(in, post, ind+1, inEnd, pindex);
    node->left=buildutil(in, post, inStrt, ind-1, pindex);

    return node;
}

struct Node* buildtree(int in[], int post[], int n)
{
    int pindex=n-1;
    return buildutil(in, post, 0, n-1, &pindex);
}

int nsum(struct Node *node, int sum)
{
    if(node==NULL)
        return sum;
    sum=node->data+nsum(node->left, sum)+nsum(node->right, sum);
}

int ntrav(int nodeval, struct Node* node)
{
    if(node==NULL)
        return -1;

    if (nodeval == node->data)
    {
        return nsum(node, node->data);
    }

    ntrav(nodeval, node->left);
    ntrav(nodeval, node->right);
}

void display(struct Node* t)
{
    if(t==NULL)
        return;
    printf("%d ", t->data);
    display(t->left);
    display(t->right);
}

int main()
{
    int n;
    printf("Enter the number of nodes in the tree: ");
    scanf("%d", &n);
    int *in=malloc(sizeof(int)*n);
    int *post=malloc(sizeof(int)*n);

    printf("Enter the inorder traversal-\n");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &in[i]);
    }
    printf("Enter the postorder traversal-\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &post[i]);
    }
    
    struct Node* root=buildtree(in, post, n);
    printf("The preorder traversal of the tree is- ");
    display(root);
    
    int ns;
    printf("\nEnter the node for which you want to find the sum: ");
    scanf("%d", &ns);
    printf("The sum is %d\n", ntrav(ns, root));
}