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

void SelectionSort(int arr[],int size)
{
    for ( int pass = 0 ; pass < size-1 ; pass++)
    {
        int min_index = pass;
        for ( int i = pass ; i < size ; i++)
            if ( arr[min_index] > arr[i] )
                min_index = i;
        if ( min_index != pass)
            swap(&arr[pass], &arr[min_index]);         
    }
}

int main()
{
    int arr[] = {7,3,4,8,1,5};
    int size = sizeof(arr)/sizeof(int);
    PrintArray(arr, size);
    SelectionSort(arr, size);
    PrintArray(arr, size);
    return 0;
}