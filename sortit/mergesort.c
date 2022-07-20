#include <stdio.h>
#include <stdlib.h>

void display(int arr[])
{
    for (int i = 0; i < 20; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1];
    int R[n2];
    for (i = 0; i < n1; i++)
    {
        L[i] = arr[i + l];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = arr[j + m + 1];
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
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void main()
{
    int arr[20];
    for (int i = 0; i < 20; i++)
        arr[i] = rand() % 100;
    display(arr);
    int len = 20;

    mergesort(arr, 0, len - 1);
    printf("After mergesort-\n");
    display(arr);
}