#include<stdio.h>
// #define RECURSION 1
// #define MEMORIZATION 1
#define TOP_DOWN 1
int dp[4+1][10+1];

int MAX(int x,int y) {
    return (x)>(y)?x:y;
}
 
#if RECURSION
int knapsack(int wt[],int val[],int W,int n){
    if( n == 0 || W == 0)
        return 0;
    if(wt[n-1] <= W)
        return MAX((val[n-1]+ knapsack(wt,val,W-wt[n-1],n-1)), knapsack(wt,val,W,n-1));
    else if (wt[n-1] > W)
        return knapsack(wt,val,W,n-1);
}
#elif MEMORIZATION
int knapsack(int wt[],int val[],int W,int n){
    if( n == 0 || W == 0)
        return 0;
    if ( dp[n][W] != -1) 
        return dp[n][W];
    if(wt[n-1] <= W)
        return dp[n][W] = MAX((val[n-1]+ knapsack(wt,val,W-wt[n-1],n-1)), knapsack(wt,val,W,n-1));
    else if (wt[n-1] > W)
        return dp[n][W] = knapsack(wt,val,W,n-1);
}
#elif TOP_DOWN
int knapsack(int wt[],int val[],int W,int n){
    // intialization
    for(int i = 0 ; i < n+1 ; i++)
        for (int j = 0; j < W+1; j++)
            dp[i][j] = 0;
    
    for(int i = 1 ; i < n+1 ; i++){
        for (int j = 1; j < W+1; j++){
            if(wt[i-1] <= j)
            dp[i][j] = MAX((val[i-1]+ dp[i-1][j-wt[i-1]]), dp[i-1][j]);
        else if (wt[n-1] > j)
            dp[i][j] = dp[i-1][j];
        }        
    }
        return dp[n][W];
}
#endif
int main(){
    int wt[] = {1,4,2,5};
    int val[] = {1,5,4,7};
    int W = 7;
    int n = 4;
#if MEMORIZATION
    for(int i = 0 ; i < n+1 ; i++){
        for(int j = 0 ; j < W+1 ; j++){
            dp[i][j] = -1;
        }
    }
#endif
    int max_profit = knapsack(wt,val,W,n);  
    printf("max profit : %d\n",max_profit);
    for(int i = 0 ; i < n+1 ; i++){
    for (int j = 0; j < W+1; j++){
        printf("%d ",dp[i][j]);   
    }
    printf("\n");
}
}