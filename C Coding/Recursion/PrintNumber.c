#include<stdio.h>

void TailPrintNum(int n)
{
    if ( n == 0 )
        return;
    
    printf("%d\n",n);
    // recursive relation
    TailPrintNum(n-1);
}

void HeadRecursion(int n)
{
        if ( n == 0 )
        return;
    // recursive relation
    HeadRecursion(n-1);
    printf("%d\n",n);
}

int main()
{
    int num;
    printf("Enter Number : ");
    scanf("%d",&num);
    printf("tail recursion\n");
    TailPrintNum(num);
    printf("\nhead recursion\n");
    HeadRecursion(num);
    return 0;
}