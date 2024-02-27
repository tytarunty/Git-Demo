// WAP to calculate 2 to the power n
#include<stdio.h>

int power(int n)
{
    if(n == 0)
        return 1;
    return 2 * power(n-1);
}

int  main()
{
    int n, ans;
    printf("Enter Power : ");
    scanf("%d",&n);

    ans = power(n);
    printf("%d\n",ans);
    return 0;
}