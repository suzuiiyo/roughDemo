#include<stdio.h>

int main()
{
    char str1[100], str2[100], *p=str1;
    int  n=0;
    printf("enter the first string: ");
    scanf("%s ", str1);
    printf("enter the second string: ");
    scanf("%s ", str2);

    while(*p++!='\0');
    --p;

    while(str2[n]!='\0')
    {
        *p++=str2[n];
        ++n;
    }
    *p='\0';
    printf("result is : %s ", str1);
    return 0;
}