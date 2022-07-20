#include <stdio.h>
#include <stdlib.h>

void shelly(int arr[], int len)
{
    for (int gap = len/2; gap > 0; gap/=2)
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

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void display(int arr[])
{
    for (int i = 0; i < 20; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void main()
{
    int arr[20];
    for (int i = 0; i < 20; i++)
        arr[i] = rand() % 100;
    display(arr);
    shelly(arr, 20);
    printf("The array after shellsort is-\n");
    display(arr);
}