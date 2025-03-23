/* Problem Statement
Given an array arr[] of size N and an integer K. Find the maximum for each and every contiguous subarray of size K.

Example:

Input 1:
    A = [1, 3, -1, -3, 5, 3, 6, 7]
    B = 3
Output 1:
    C = [3, 3, 5, 5, 6, 7] . 
*/

#include<stdio.h>
#include<limits.h>
void slidingwindow(int arr[],int size, int k){
    int i=0,j=0,max = INT_MIN;

    while(j < size){
        if(max < arr[j])
            max = arr[j];

        if( j-i+1 == k ){
            printf("%d\n",max);
            i++;
            j++;
        }
        else{
            j++;
        }
    }
}

int main(){
    int arr[8] = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    int size = sizeof(arr) / sizeof(int);
    slidingwindow(arr,size,k);
    return 0;
}