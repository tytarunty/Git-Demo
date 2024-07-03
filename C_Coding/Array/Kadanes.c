#include<stdio.h>

#define KADANES_ALGO

int main()
{
    int arr[] = {1,2,-3,2,3,-4,2,4,-5,2};
    int maxSum = arr[0], currSum = 0;
    int size = sizeof(arr)/sizeof(arr[0]);

#ifdef KADANES_ALGO
// Kadanes algorithm --> O(n)
    for (int i = 0 ; i < size ; i++)
    {
        currSum = currSum + arr[i];

        if (maxSum < currSum)
            maxSum = currSum;
        if (currSum <= 0)
            currSum = 0;
    }
#else   //BRUTE_FORCE --> O(n^2)
    for ( int i=0 ; i<size ; i++)
    {
        currSum = 0;
        for(int j=i+1 ;j<size ; j++)
        {
            currSum = currSum + arr[j];
            if (maxSum < currSum)
                maxSum = currSum;
        }
    }
#endif

    printf("MaxSum : %d\n",maxSum);
    return 0;
}