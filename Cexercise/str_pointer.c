#include<stdio.h>
#include<string.h>

void main()
{
    char ch[10];
    char *p=ch;
    char *ptr ="£ºthat's all entered strings!";
    printf("please enter the string: \n");
    scanf("%s", p);
    //printf("%s \n", ch);
    strcat( p, ptr);
    printf("the copied string is: %s", ch);
    
}