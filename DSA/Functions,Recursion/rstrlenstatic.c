#include<stdio.h>
int len(char* str)
{
    static int count=0;
    if(*str=='\0')
    {
        return count;
    }
    count++;
    return len(str+1);
}

int main()
{
    char str[100];
    printf("Enter string:- ");
    scanf("%s",str);
    printf("\nLength of string is %d",len(str));
}