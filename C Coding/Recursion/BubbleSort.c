#include<stdio.h>

void PrintArray(int arr[], int size)
{
    for (int i=0 ; i<size ; i++)
        printf("%d ",arr[i]);
    printf("\n");
}

void swap(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

void BubbleSort(int arr[],int size)
{
    // base case
    if ( size == 0 || size == 1 )
        return;
    
    // move largest element to end
    for ( int i = 0 ; i < size-1 ; i++)
        if ( arr[i] > arr[i+1] )
            swap(&arr[i], &arr[i+1]);
    
    // recursive call
    BubbleSort(arr, size-1);
}

int main()
{
    int arr[] = {7,3,4,8,1,5};
    int size = sizeof(arr)/sizeof(int);
    PrintArray(arr, size);
    BubbleSort(arr, size);
    PrintArray(arr, size);
    return 0;
}