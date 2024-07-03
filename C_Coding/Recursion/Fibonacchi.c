// find nth term of fibonnacci series
#include<stdio.h>

int Fibonnacci(int n)
{
    // base case
    if (n == 0)
        return 0 ;
    if (n == 1)
        return 1;
    
    // recursive relation
    // f(n) = f(n-1) + f(n-2)
    int ans = Fibonnacci(n-1) + Fibonnacci(n-2);
    printf("%d ",ans);
    return ans;
}

int main()
{
    int n;
    printf("Enter Number : ");
    scanf("%d",&n);

    printf("%d\n",Fibonnacci(n));
    return 0;
}