#include <stdio.h>

void traverse(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main()
{
    int arr[] = {1, 2, 1, 3, 4, 2, 8, 0, 8, 4};
    int n = 10;
    bubbleSort(arr, n);
    printf("Sorted array: \n");
    traverse(arr, n);
    return 0;
}
