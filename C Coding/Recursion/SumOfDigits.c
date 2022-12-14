// WAP to find sum of digits of a number
#include<stdio.h>

int Sum(int n)
{
    if (n/10 == 0)
        return n; 
    return (n%10)+Sum(n/10);
    
}

void main()
{
    int num;
    printf("Enter Number : ");
    scanf("%d",&num);
    printf("Sum of digits of %d is %d",num,Sum(num));
}