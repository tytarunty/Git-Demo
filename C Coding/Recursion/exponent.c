// find a to the power b
#include<stdio.h>

int power(int a, int b)
{
    // base case
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    
    // recursive call
    int ans = power(a,b/2);

    // if b is odd
    if (b % 2)
        return  a * ans * ans ;
    else  
    // if b is even  
        return  ans * ans ;
}

int main()
{
    int a,b;
    printf("Enter number : ");
    scanf("%d",&a);
    printf("Enter power : ");
    scanf("%d",&b);

    int ans = power(a,b);
    printf("%d to the power %d is %d\n",a,b,ans);
    return 0;
}