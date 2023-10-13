#include<stdio.h>
#define CAPACITY 100

void display(int arr[],int size)
{
    // Array Traversal
    for (int i=0 ; i<size ; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int IndexDeletion(int arr[], int index, int size)
{
    // Error check : Empty Array
    if ( size == 0)
    {
        printf("Empty Array, no element to delete\n");
        return size;
    }
    // Error check : Given index is greater than array used size
    else if (index > size-1)
    {
        printf("Index is greater than size of array\n");
        return size;
    }

    // code for deletion of element in array
    for (int i=index ; i < size ; i++ )
    {
        arr[i]=arr[i+1];
    }
    return size-1;
}

int main()
{
    int arr[CAPACITY]={0,1,2,3,5,6},size=6,index=1;
    display(arr,size);
    size=IndexDeletion(arr, index,size);
    display(arr,size);
    return 0;
}