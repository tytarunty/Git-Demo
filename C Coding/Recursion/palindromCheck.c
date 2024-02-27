#include<stdio.h>
#include<string.h>

int checkPlaindrom(char str[], int i, int j)
{
    // base case
    if(i > j)
        return 1;
    if (str[i] != str[j])
        return 0;
    else
        // recursive call
        return checkPlaindrom(str, i+1, j-1);
}

int main()
{
    char str[] = "abbccbba";
    if (checkPlaindrom(str, 0, strlen(str)-1))
        printf("palindrom\n");
    else
        printf("not a palindrom\n");
    return 0;
}