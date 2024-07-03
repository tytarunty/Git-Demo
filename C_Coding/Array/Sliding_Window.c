// Given an array of size 'n'. WAP to find out sum of contigeous subarray of size 'k'
#include<stdio.h>
// #define SLIDING_WINDOW


int main()
{
    int n=8,k=4;
    int arr[8] = {1,2,3,4,3,2,1,0};
    int maxsum = 0;
    int cur_sum = 0;
#ifdef SLIDING_WINDOW  // SLIDING_WINDOW --> O(n)
    for ( int i=0 ;i<k ;i++)
        cur_sum = cur_sum + arr[i];
    for (int i=1 ; i<n-k ; i++ )
    {
        cur_sum = cur_sum - arr[i-1]+ arr[i+k-1];
        if (maxsum < cur_sum)
            maxsum = cur_sum;
    }
#else //BRUTE FORCE --> O(nk)
    for (int i=0 ; i<n-k ; i++ )
    {
        int cur_sum = 0;
        for ( int j = 0 ; j<k ; j++){
            cur_sum = cur_sum + arr[j+i];
        }
        if (maxsum < cur_sum)
            maxsum = cur_sum;
    }
#endif

    printf("Max SUm : %d\n",maxsum);
    return 0;
}


