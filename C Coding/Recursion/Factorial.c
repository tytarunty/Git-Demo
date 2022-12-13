#include<stdio.h>

int Factorial(int num){
    if (num == 1)  // base condition
        return 1 ;
    return num*Factorial(num - 1); 
}

void main()
{
    int num;
    printf("Enter Number : ");
    scanf("%d",&num);
    printf("Factorail of %d is %d",num,Factorial(num));
}