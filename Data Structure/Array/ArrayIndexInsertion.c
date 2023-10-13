// WAP to insert an element at a given index in an array

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

int IndexInsert(int arr[], int element, int index, int size, int capacity)
{
    // Error check : Array overflow
    if (size >= capacity)
    {
        printf("No space left, array is full\n");
        return size;
    }

    // code for insertion of element in array
    for (int i=size ; i >= index ; i-- )
    {
        arr[i+1]=arr[i];
    }
    arr[index]=element;
    return size+1;
}

int main()
{
    int arr[CAPACITY]={0,1,2,3,5,6},size=6,element=4,index=2;
    display(arr,size);
    size = IndexInsert(arr,element,index,size,CAPACITY);
    display(arr,size);
    return 0;
}