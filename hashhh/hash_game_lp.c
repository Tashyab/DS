#include <stdio.h>
#include <stdlib.h>

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != -1)
            if (i < 10)
                printf("0%d | %d\n", i, arr[i]);
            else
                printf("%d | %d\n", i, arr[i]);
        else
            printf("%d | <E>\n", i);
    }
}

void findwinner(int arr[], int asize, int tarr[], int n, int key)
{
    int win = 0;
    int ptr = 0;
    int off = 0;
    for (int i = 0; i < n; i++)
    {
        if(key==tarr[i])
        {
            win = 1;
            printf("{");
            for (int k = off; k <= ptr; k++)
            {
                if (k < ptr)
                    printf("%d,", arr[k]);
                else
                    printf("%d", arr[k]);
            }
            printf("}\n");
        }
        if (ptr < asize)
            ptr++;
        else
            ptr = ++off;
    }
    if(win==1)
        printf("B is the winner.");
    else
        printf("Haha, %d is not there.\nA is the winner.", key);
}

void main()
{
    int asize;
    printf("Enter the size of array A: ");
    scanf("%d", &asize);
    int a[asize];
    printf("Enter the array: ");
    for (int i = 0; i < asize; i++)
    {
        int n;
        scanf("%d", &n);
        a[i] = n;
    }

    int tsize = (asize * (asize + 1)) / 2;
    int tablea[tsize];
    for (int i = 0; i < tsize; i++)
    {
        tablea[i] = 0;
    }

    int ind = 0;
    for (int i = 0; i < asize; i++)
    {
        for (int j = i; j < asize; j++)
        {
            for (int k = i; k <= j; k++)
            {
                tablea[ind] = tablea[ind] + a[k];
            }
            ind++;
        }
    }
    display(tablea, tsize);

    int b;
    printf("Enter the value to find, B: ");
    scanf("%d", &b);
    findwinner(a, asize, tablea, tsize, b);
    printf("\nThe number of collisions is 0.\n");
}