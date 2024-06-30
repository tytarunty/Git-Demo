#include<stdio.h>

int LinearSearch(int arr[] ,int l, int r, int item)
{
    while ( l <= r )
    {    
        int mid = (l+r)/2;
        //int mid = l + (r-l)/2;
        printf("MID : %d\n",mid);
        if ( item == arr[mid])
            return 1;
        else if ( item < arr[mid])
        {
            r = mid-1;
        }
        else if ( item > arr[mid])
        {
            l = mid+1;
        }
    }    
    return 0;
}

int main()
{
    int arr[10] = {0,1,2,3,4,5,6,7,8,9};
    if (LinearSearch(arr,0,9,3))
        printf("%d found \n",1);
    else
        printf("%d not found \n",2);
    
    return 0;
}