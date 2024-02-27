#include<stdio.h>
#include<string.h>

void swap(char str[],int i,int j)
{
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
}

void reverse(char str[], int i, int j)
{
    // base case
    if(i > j)
        return;

    // processing
    swap(str,i,j);
    i++;
    j--;

    // recursive call
    reverse(str, i, j);
}

int main()
{
    char str[] = "abcdefg";
    reverse(str, 0, strlen(str)-1);
    printf("%s\n",str);

    return 0;
}