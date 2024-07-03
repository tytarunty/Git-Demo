#include<stdio.h>
#include<string.h>

int main()
{
    int count[26] = {0};
    char *s = "Aaabbbcccfahugshjgcd $^&&*(%gic gfigh lihc iuhiuhbacliua";
    for ( int i = 0 ; i<strlen(s); i++)
    {
        if ( s[i] >= 'a' &&  s[i] <= 'z')
            count[s[i]-'a']++;
        else if ( s[i] >= 'A' &&  s[i] <= 'Z')
            count[s[i]-'A']++;
    }
        

    for ( int i = 0 ; i<26; i++)
        if (count[i] != 0)
            printf("%c : %d\n",i+'A',count[i]);
    return 0;
}