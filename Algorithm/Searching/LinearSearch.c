#include<stdio.h>

int LinearSearch(int arr[] ,int size, int item)
{
    int i=0;
    while ( i< size && item != arr[i])
        i++;
    if ( i<size)
        return i;
    return -1;
    
}

int main()
{
    int arr[10] = {96,19,85,9,16,29,2,36,41,67},index=LinearSearch(arr,10,41);
    if (index != -1)
        printf("%d found at index %d\n",41,index);
    else
        printf("%d not found n",41);
    
    return 0;
}