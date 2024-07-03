#include<stdio.h>

int BinarySearch(int arr[], int start,int end, int element)
{
    // base case
    if (start > end)
        return -1;

    int mid = (start + end)/2,ans;
    if(arr[mid] == element)
        return mid;
    else if(element < arr[mid])
        ans =  BinarySearch(arr, start, mid-1, element );
    else if(element > arr[mid])
        ans = BinarySearch(arr , mid+1, end, element);
    
    return ans;
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9}, element;
    int size = sizeof(arr) / sizeof(int);
    printf("Enter number to search : ");
    scanf("%d",&element);
    int ans = BinarySearch(arr, 0, size-1,element);
    if (ans == -1)
        printf("%d not found in array\n",element);
    else
        printf("%d found in array at %d index\n",element,ans);
    return 0;
}