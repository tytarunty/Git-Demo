/* Problem Statement :
Given an array containing N positive integers and an integer K. Your task is to find the length of the longest Sub-Array with sum of the elements equal to the given value K.

For Input:
1
7 5
4 1 1 1 2 3 5
your output is: 
4 . 
*/

#include<stdio.h>

int slidingwindow(int arr[],int size,int k){
    int left=0,right=0,curren_sum=0,max_len=0;
    while(right < size)
    {
        curren_sum += arr[right];
        while ( curren_sum > k && left <= right){
            curren_sum -= arr[left];
            left++;
        }

        if(curren_sum == k){
            int subarray_len = right - left + 1;
            if(subarray_len > max_len )
                max_len = subarray_len;
            
        }
        right++;
    }
    return max_len;
}

int main(){
    int arr[] = {4,1,1,1,2,3,5};
    int size = sizeof(arr)/ sizeof(arr[0]);
    int k = 5;
    printf("Ans : %d\n",slidingwindow(arr,size, k));
    return 0;
}