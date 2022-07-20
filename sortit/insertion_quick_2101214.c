#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int c;
int s;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            c++;
            i++;
            swap(&arr[i], &arr[j]);
            s++;
        }
    }
    swap(&arr[i + 1], &arr[high]);
    s++;
    return (i + 1);
}

void quicky(int arr[], int low, int high)
{
    if (low < high)
    {
        int part_index = partition(arr, low, high);
        quicky(arr, low, part_index - 1);
        quicky(arr, part_index + 1, high);
    }
}

void inserty(int arr[], int len)
{
    int i, j, org;
    for (i = 1; i < len; i++)
    {
        org = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > org)
        {
            s++;
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = org;
        c++;
    }
}

void insertwithlh(int arr[], int l, int h)
{
    int i, j, org;
    for (i = l + 1; i < h; i++)
    {
        org = arr[i];
        j = i - 1;

        while (j >= l && arr[j] > org)
        {
            s++;
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = org;
        c++;
    }
}

void hybridsort(int arr[], int low, int high)
{
    if (high <= low)
        return;
    int i, j, org, part_index;
    if (high - low >= 50)
    {
        part_index = partition(arr, low, high);
        hybridsort(arr, low, part_index - 1);
        hybridsort(arr, part_index + 1, high);
    }
    else
    {
        insertwithlh(arr, low, high);
    }
}

void county(char arr[])
{
    char out[strlen(arr)];
    int count[100];
    int i;
    memset(count, 0, sizeof(count));

    for (i = 0; i < strlen(arr); i++)
        count[arr[i]]++;

    for (i = 1; i < 100; i++)
        count[i] += count[i - 1];

    for (i = 0; arr[i]; i++)
    {
        out[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (i = 0; arr[i]; i++)
        arr[i] = out[i];
}

void printarr(int arr[], int arrsize)
{
    for (int i = 0; i < arrsize; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("The number of comparisons are %d.\n", c);
    printf("The number of swaps are %d.\n", s);
    printf("\n");
    c = 0;
    s = 0;
}

void main()
{
    int arrsize = 1000;
    int n;
    int flag = 0;
    int a[arrsize];

    printf("Enter the upper limit: ");
    scanf("%d", &n);
    printf("\n");
    printf("The Original array A is:\n");
    for (int i = 0; i < arrsize; i++)
    {
        a[i] = rand() % n;
        printf("%d ", a[i]);
    }
    printf("\n");

    int a2[arrsize];
    for (int i = 0; i < arrsize; i++)
        a2[i] = a[i];

    printf("\n");
    inserty(a2, arrsize);
    printf("The array after insertion sort is:\n");
    printarr(a2, arrsize);

    for (int i = 0; i < arrsize; i++)
        a2[i] = a[i];

    quicky(a2, 0, arrsize - 1);
    printf("The array after quicksort is:\n");
    printarr(a2, arrsize);

    arrsize = arrsize + 10;
    int b[arrsize];
    for (int i = 0; i < arrsize; i++)
    {
        if (i < arrsize - 10)
            b[i] = a2[i];
        else
            b[i] = rand() % n;
    }

    printf("The new array B is:\n");
    for (int i = 0; i < arrsize; i++)
        printf("%d ", b[i]);
    printf("\n");

    int b2[arrsize];
    for (int i = 0; i < arrsize; i++)
        b2[i] = b[i];

    printf("\n");
    inserty(b2, arrsize);
    printf("The array after insertion sort is:\n");
    printarr(b2, arrsize);

    for (int i = 0; i < arrsize; i++)
        b2[i] = b[i];

    quicky(b2, 0, arrsize - 1);
    printf("The array after quicksort is:\n");
    printarr(b2, arrsize);
    printf("\n");

    hybridsort(a, 0, arrsize-1);
    printf("The array A after hybridsort is:\n");
    printarr(a, arrsize);

    printf("\n");
    arrsize = arrsize + 10;

    hybridsort(b, 0, arrsize-1);
    printf("The array B after hybridsort is:\n");
    printarr(b, arrsize);

    // question 4
    printf("Enter the size of sequence: ");
    int seqsize, meraint, apnaint = 0;
    scanf("%d", &seqsize);
    getchar();
    char c[seqsize];
    for (int i = 0; i < seqsize; i++)
    {
        printf("Enter character %d: ", i + 1);
        scanf("%c", &c[i]);
        getchar();
    }
    county(c);
    printf("\nAfter Sorting the sequence, the result is : ");
    for (int i = 0; i < seqsize; i++)
    {
        printf("%c ", c[i]);
    }
    printf("\n");
}