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

    // base condition
    if ( size == 0 || size == 1 )
        return;

    int min_index = 0;
    for ( int i = 0 ; i < size ; i++)
    {
        if (arr[min_index] > arr[i])
            min_index = i;
    }
    if (min_index != 0)        
        swap(&arr[0], &arr[min_index]);
    SelectionSort(arr+1,size-1);
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