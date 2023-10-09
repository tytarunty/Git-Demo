// WAP to Find the largest three distinct elements in an array
// Input: arr[] = {10, 4, 3, 50, 23, 90}

#include<stdio.h>
#include <limits.h> /* For INT_MIN */

void Print3Largest(int arr[],int n)
{
    /* There should be atleast three elements */
    if (n < 3) { 
        printf(" Invalid Input "); 
        return;
    }

    int first,second,third;
    first=second=third=INT_MIN;
    for (int i = 0 ; i < n ; i++){
        if (arr[i] > first){
            third  = second;
            second = first;
            first  = arr[i];
        }
        else if ( arr[i] > second){
            third  = second;
            second = arr[i];
        }
        else if ( arr[i] > third ){
            third = arr[i];
        }
    }

    printf("first : %d , second : %d , third : %d\n",first,second,third);
}

int main()
{
    int arr[]={10, 4, 3, 50, 23, 90};
    int n = sizeof(arr)/sizeof(int);
    Print3Largest(arr,n);
    return 0;
}