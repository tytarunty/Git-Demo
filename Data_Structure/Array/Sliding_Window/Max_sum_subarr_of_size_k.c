#include<stdio.h>
#include<limits.h>

int max_sum = INT_MIN;

int slidingwindow(int arr[],int size, int k){
	int i=0,j=0;
	int sum = 0;
	while(j<size){
		sum += arr[j];
		
		if ( j-i+1 == k){
			if ( max_sum < sum)
				max_sum = sum;
			sum = sum - arr[i++];
			j++;
		}
		else{
			j++;
		}
	}
	return max_sum;
}

int main(){
	int arr[7] = {2,5,1,8,2,9,1};
    int k = 3;
    int size = sizeof(arr) / sizeof(int);;
    printf("Max sum of subarray of size %d is %d \n",k,slidingwindow(arr,size,k));
}