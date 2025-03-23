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
int max_arr[8] = {INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN};

void slidingwindow(int arr[],int size, int k){
    int i=0,j=0,max = INT_MIN,f=0,r=0;

    while(j < size){
        
        if(max_arr[r] < arr[j]){
            max_arr[r] = arr[j];
            r++;
        }

        while ( f < r && (max_arr[f] < arr[j] || f < i)){
            f++;
        } 

        if(max < arr[j])
            max = arr[j];
        
        if( j-i+1 == k ){
            printf("%d\n",max_arr[f]);
            i++;
            j++;
        }
        else{
            j++;
        }
        if ( arr[j] == max )
            max = INT_MIN;
    }
}

int main(){
    int arr[8] = {1,3,1,-3,5,60,-3,70};
    int k = 3;
    int size = sizeof(arr) / sizeof(int);
    slidingwindow(arr,size,k);
    return 0;
}