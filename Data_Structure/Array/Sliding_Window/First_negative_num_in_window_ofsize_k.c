/* Problem Statement
Given an array and a positive integer k, find the first negative integer for each and every window(contiguous subarray) of size k.

Example:

Input:
2
5
-8 2 3 -6 10
2
8
12 -1 -7 8 -15 30 16 28
3

Output:
-8 0 -6 -6
-1 -1 -7 -15 -15 0 . 
*/
#include<stdio.h>
#include<limits.h>

int max_sum = INT_MIN;
int neg_arr[7] = {0};

int slidingwindow(int arr[],int size, int k){
	int i=0,j=0,f=0,r=0;
	int sum = 0;
	while(j<size){
		if ( arr[j] < 0)
        {
            neg_arr[r] = arr[j];
            r++; 
        }

		if ( j-i+1 == k){
            printf("front : %d, neg num : %2d\n", f, neg_arr[f]);
            if ( arr[i] == neg_arr[f]){
                f++;
            }
            i++;
			j++;
		}
		else{
			j++;
		}
        
	}
	return max_sum;
}

int main(){
	int arr[8] = {12,-1,-7,8,-15,30,16,28};
    int k = 3;
    int size = sizeof(arr) / sizeof(int);;
    slidingwindow(arr,size,k);
}