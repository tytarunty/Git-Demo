#include<stdio.h>

int Checksorted(int arr[],int size)
{
    if (size == 0 || size == 1)
        return 1;
    if (arr[0] < arr[1])
        return Checksorted(arr+1 , size-1);
    else
        return 0;
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int size = sizeof(arr) / sizeof(int);
    if (Checksorted(arr,size))
        printf("Array is sorted\n");
    else
        printf("Array is not sorted\n");
    return 0;
}