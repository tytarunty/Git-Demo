// Display the digits of positive interegr number in reverse order
#include<stdio.h>

void Reverse(int n)
{
    if (n == 0)
        return;
    printf("%d",n%10);
    Reverse(n/10);
}

void main()
{
    int num;
    printf("Enter Numner : ");
    scanf("%d",&num);
    Reverse(num);
}