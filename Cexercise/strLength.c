#include<stdio.h>

int main()
{
    char str[100];
    int i=0;
    printf("enter the string: ");
    scanf("%s", str);

    for(i=0; str[i]!='\0'; i++);

    printf("the length of the str is: %d", i);
    return 0;
}