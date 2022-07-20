#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyMax(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapifyMax(arr, n, largest);
    }
}

void heapifyMin(int arr[], int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;
    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i)
    {
        swap(&arr[i], &arr[smallest]);
        heapifyMin(arr, n, smallest);
    }
}

void heapsort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapifyMax(arr, n, i); // Create max heap
    }
    for (int i = n - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]); // Heapsorting array
        heapifyMax(arr, i, 0);
    }
}

void display(int arr[], int len)
{
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    heapsort(arr, n);
    printf("The sorted array is:\n");
    display(arr, n);
}