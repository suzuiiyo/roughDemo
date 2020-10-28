#include<stdio.h>
#include<string.h>

int main()
{
    char str1[100], str2[100], *p=str1;
    int i;
    
    printf("enter the first string: \n");
    scanf("%s", str1);
    printf("enter the second string: \n");
    scanf("%s", str2);

    for(i=0; str2[i]!='\0'; ++i)
    {
        *(p+i)=str2[i];
    }

    str1[i] ='\0';
    printf("%s", str1);
    return 0;
}