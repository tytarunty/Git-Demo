#include<stdio.h>

int LinearSearch(int arr[], int size, int element)
{
    if (size == 0)
        return 0;

    if (arr[0] == element) 
        return size;
    else{
        int remaningPart = LinearSearch(arr+1, size-1, element);
        return remaningPart;
    }
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9}, element;
    int size = sizeof(arr) / sizeof(int);
    printf("Enter number to search : ");
    scanf("%d",&element);
    int ans = LinearSearch(arr, size,element);
    if (ans)
        printf("%d found in array at %d index\n",element,size-ans);
    else
    printf("%d not found in array\n",element);
    return 0;
}