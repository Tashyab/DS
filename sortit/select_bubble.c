#include <stdio.h>
#include <stdlib.h>

void display(int arr[])
{
    for (int i = 0; i < 20; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void main()
{
    int arr[20];
    int arr2[20];
    for (int i = 0; i < 20; i++)
    {
        arr[i] = rand() % 100;
        arr2[i] = arr[i];
    }
    display(arr);
    int min;
    for (int i = 0; i < 20; i++)
    {
        int min = arr[i];
        int min_ind = i;
        for (int j = i + 1; j < 20; j++)
        {
            if (arr[j] < min)
            {
                min_ind = j;
                min = arr[j];
            }
        }
        swap(&arr[i], &arr[min_ind]);
    }
    printf("After selection sort-\n");
    display(arr);

    int len = 20;
    int key = 0;
    for (int i = 0; i < len-1; i++)
    {
        key = 0;
        for (int j = 0; j < len-i-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(&arr[j], &arr[j + 1]);
                key = 1;
            }
        }
        if(key==0)
            break;
    }
    printf("After bubble sort-\n");
    display(arr);
}