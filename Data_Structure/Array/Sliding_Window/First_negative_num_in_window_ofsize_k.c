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