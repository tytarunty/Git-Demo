// WAP to find factorial of a positive number
#include<stdio.h>

int Factorial(int num){
    if (num == 1)  // base condition
        return 1 ;
    return num*Factorial(num - 1); 
}

void main()
{
    signed long int num;
    printf("Enter Number : ");
    scanf("%d",&num);
    if (num == 0 )
        printf("Factorail of 0 is 1");
    printf("Factorail of %d is %d",num,Factorial(num));
}