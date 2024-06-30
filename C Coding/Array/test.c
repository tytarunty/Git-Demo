#include<stdio.h>

int LinearSearch(int arr[] ,int l, int r, int item)
{
    while(l<=r)
    {
        int mid = (l+r)/2;
        if (arr[mid] == item)
            return mid;
        if (item < arr[mid])
            r = mid-1;
        if (item > arr[mid])
            l= mid +1;
    }
    return -1;
}

int main()
{
    int arr[10] = {0,1,2,3,4,5,6,7,8,9};
    if (LinearSearch(arr,0,9,4) == -1)
        printf("%d not found \n",3);   
    else
        printf("%d found \n",3);
        
    
    return 0;
}