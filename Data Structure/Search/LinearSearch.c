// WAP for Linear Search.
// Linear search is done using array traversal.

#include<stdio.h>

void LinearSearch(int arr[],int size, int element )
{
    for (int i=0 ; i < size ; i++)
    {
        if (arr[i] == element)
        {
            printf("%d found at %dth index\n",element,i);
            return;
        }
    }
    printf("%d is not found in array\n",element);
}

int main()
{
    int arr[100]={4,7,5,22,466,33,556,732,22,1};
    LinearSearch(arr, 10, 1);
    return 0;
}