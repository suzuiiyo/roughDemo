#include<stdio.h>
#include<string.h>

char* reverseStr(char* str);

int main()
{
    char str[30];
    printf("please enter the string:\n");
    scanf("%s", str);

    reverseStr(str);
    printf("the reversed string is:%s", str);
    return 0;
}

char* reverseStr(char* str)
{
    int i=0;
    int j=strlen(str)-1;
    char temp;
    while(i<j)
    {
        temp = *(str+i);
        *(str+i) = *(str+j);
        *(str+j) = temp;
        i++;
        j--;
    }
    
    return str;
}