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
    for ( int pass = 0 ; pass < size-1 ; pass++)
        for ( int i = 0 ; i < size-1-pass ; i++)
            if ( arr[i] > arr[i+1] )
                swap(&arr[i], &arr[i+1]);

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