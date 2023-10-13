// WAP for Binary Search in an array
// Binary search can be performed only on sorted array

#include<stdio.h>

void BinarySearch(int arr[], int size, int element)
{
    int start = 0 , end = size-1, mid;

    while ( start <= end )
    {
        mid = (start + end ) / 2;
        if ( element == arr[mid])
        {
            printf("%d found at %dth index\n ",element,mid);
            return;
        }
        else if ( element > arr[mid])
        {
            start = mid+1;
        }
        else if ( element < arr[mid])
        {
            end = mid-1 ; 
        }
    }
    printf("%d not found in arrar\n",element);
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int size=sizeof(arr)/sizeof(int);
    int element=1;
    BinarySearch(arr, size , element);
    return 0;
}  