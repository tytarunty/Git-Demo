// print number into words
#include<stdio.h>

void PrintNum(int n, char *word[])
{
    // base case
    if (n == 0)
        return ;
    
    // processing
    int digit = n % 10;
    n = n/10;

    // recursive relation
    PrintNum(n, word);
    printf("%s ",word[digit]);
}

int main()
{
    int n;
    char *word[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"} ;
    printf("Enter Number : ");
    scanf("%d",&n);

    PrintNum(n, word);
    printf("\n");
    return 0;
}