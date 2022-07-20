#include <stdio.h>
#include <stdlib.h>

void atob(int a[], int b[], int len)
{
    for (int i = 0; i < len; i++)
    {
        b[i] = a[i];
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void display(int arr[], int len)
{
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void bubbly(int arr[], int len)
{
    int key = 0;
    for (int i = 0; i < len - 1; i++)
    {
        key = 0;
        for (int j = 0; j < len - i - 1; j++)
        {
            if (arr[j + 1] < arr[j])
            {
                swap(&arr[j + 1], &arr[j]);
                key = 1;
            }
        }
        if (key == 0)
            break;
    }
}

void inserty(int arr[], int len)
{
    int i, j, org;
    for (int i = 1; i < len; i++)
    {
        j = i - 1;
        org = arr[i];
        while (j >= 0 && arr[j] > org)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = org;
    }
}

void selecty(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = i; j < len; j++)
        {
            if (arr[j] < arr[i])
                swap(&arr[j], &arr[i]);
        }
    }
}

void shelly(int arr[], int len)
{
    for (int gap = len / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < len; i++)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j = j - gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;

    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = arr[m + j + 1];
    }

    i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j > n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergy(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergy(arr, l, m);
        mergy(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int partition(int arr[], int l, int h)
{
    int pivot = arr[h];
    int i = l - 1;
    for (int j = l; j < h; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
        swap(&arr[i + 1], &arr[h]);
    }
    return i + 1;
}

void quicky(int arr[], int l, int h)
{
    if (l < h)
    {
        int part = partition(arr, l, h);
        quicky(arr, l, part - 1);
        quicky(arr, part + 1, h);
    }
}

void main()
{
    int a[] = {2, 5, 29, 12, 0, 123, 8, 1};
    int len = sizeof(a) / sizeof(a[0]);
    int b[len];

    printf("Bubblesort:\n");

    atob(a, b, len);
    display(b, len);
    bubbly(b, len);
    display(b, len);

    printf("\nInsertsort:\n");

    atob(a, b, len);
    display(b, len);
    inserty(b, len);
    display(b, len);

    printf("\nSelectsort:\n");

    atob(a, b, len);
    display(b, len);
    selecty(b, len);
    display(b, len);

    printf("\nShellsort\n");

    atob(a, b, len);
    display(b, len);
    shelly(b, len);
    display(b, len);

    printf("\nMergesort:\n");

    atob(a, b, len);
    display(b, len);
    mergy(b, 0, len - 1);
    display(b, len);

    printf("\nQuicksort:\n");

    atob(a, b, len);
    display(b, len);
    quicky(b, 0, len - 1);
    display(b, len);
}