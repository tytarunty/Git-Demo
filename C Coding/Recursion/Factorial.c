// WAP to find factorial of a positive number
#include<stdio.h>

int Factorial(int num){
    if (num == 0)  // base condition
        return 1 ;
    // recursive relation
    return num*Factorial(num - 1); 
}

// int Factorial(int num)
// {
//     if(num == 0)
//         return 1;
//     int SmallProblem = Factorial(num-1);
//     int BigProblem = num * SmallProblem;

//     return BigProblem;
// }

int main()
{
    int num;
    printf("Enter Number : ");
    scanf("%d",&num);
    printf("Factorail of %d is %d\n",num,Factorial(num));

    return 0;
}