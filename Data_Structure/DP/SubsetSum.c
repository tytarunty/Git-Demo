#include<stdio.h>
#define RECURSION
#define MEMORIZATION
#define TOP_DOWN
int dp[4+1][10+1];

#define SUBSET_SUM
#define SUBSET_SUM_COUNT

#ifdef RECURSION
int knapsack_recursion(int wt[],int W,int n){
    if (W == 0)
        return 1;
    if( n == 0 ) 
        return 0;
    int ans;
    if(wt[n-1] <= W)
        ans = knapsack_recursion(wt,W-wt[n-1],n-1) || knapsack_recursion(wt,W,n-1);
    else if (wt[n-1] > W)
        ans = knapsack_recursion(wt,W,n-1);
    return ans;
}
#endif
#ifdef MEMORIZATION
int knapsack_memorization(int wt[],int W,int n){
    if (W == 0)
        return 1;
    if( n == 0 ) 
        return 0;
    if ( dp[n][W] != -1) 
        return dp[n][W];
    if(wt[n-1] <= W)
        dp[n][W] = knapsack_memorization(wt,W-wt[n-1],n-1) || knapsack_memorization(wt,W,n-1);
    else if (wt[n-1] > W)
        dp[n][W] = knapsack_memorization(wt,W,n-1);
    return dp[n][W];
}
#endif
#ifdef TOP_DOWN
int knapsack_topdown(int wt[],int W,int n){
    // intialization
    for(int i = 0 ; i < n+1 ; i++){
        for (int j = 0; j < W+1; j++){
            if (i == 0)
                dp[i][j] = 0;
            if (j == 0)
                dp[i][j] = 1;
        }
    }
   
    // for(int j = 0 ; j < W+1 ; j++)
    //     dp[0][j] = 0;
    // for(int i = 0 ; i < n+1 ; i++)
    //     dp[i][0] = 1;
    
    for(int i = 1 ; i < n+1 ; i++){
        for (int j = 1; j < W+1; j++){
        if(wt[i-1] <= j)
            dp[i][j] =  dp[i-1][j-wt[i-1]] || dp[i-1][j];
        else if (wt[n-1] > j)
            dp[i][j] = dp[i-1][j];
        }        
    }
        return dp[n][W];
}
#endif

int main()
{
    // int arr[] = {2,3,7,8,10};
    int arr[] = {2,3,5,6,8,10};
    int sum = 8;
    int n = 6;
    int ans;
#ifdef RECURSION
    ans = knapsack_recursion(arr,sum,n);
    printf("RECURSION     : %d\n",ans);
#endif

#ifdef MEMORIZATION
    for(int i = 0 ; i < n+1 ; i++){
        for(int j = 0 ; j < sum+1 ; j++){
            dp[i][j] = -1;
        }
    }
    ans = knapsack_memorization(arr,sum,n);
    // for(int i = 0 ; i < n+1 ; i++){
    //     for(int j = 0 ; j < sum+1 ; j++){
    //          printf("%d ",dp[i][j]);
    //     }
    //     printf("\n");
    // }
    printf("MEMORIZATION  : %d\n",ans);
#endif

#ifdef TOP_DOWN
    ans = knapsack_topdown(arr,sum,n);
    // for(int i = 0 ; i < n+1 ; i++){
    //     for(int j = 0 ; j < sum+1 ; j++){
    //          printf("%d ",dp[i][j]);
    //     }
    //     printf("\n");
    // }
    printf("TOP_DOWN      : %d\n",ans);
#endif
    return 0;
}