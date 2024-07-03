#include<stdio.h>

int SumAray(int arr[], int size)
{
    static int sum = 0;
    if(size == 1)
        return arr[0];

    sum = arr[0] + SumAray(arr+1, size-1);
    return sum;
}

int main()
{
    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr)/sizeof(int);
    int sum = SumAray(arr , size);
    printf("Sum of array elements : %d\n",sum);
    return 0;
}