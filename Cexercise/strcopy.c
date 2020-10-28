#include<stdio.h>

int main()
{
    char s1[100], s2[100], i, j;

    printf("enter the first string: ");
    scanf("%s", s1);

    printf("enter the second string: ");
    scanf("%s", s2);

    //measure the length of the string s1
    for(i=0; s1[i]!='\0'; ++i);
    //printf("%d \n", i);

    for(j=0; s2[j]!='\0'; ++j);
    {
        s1[i] = s2[j];
        ++i;
    }

    //printf("%d \n", i);
    s1[i]='\0';
    printf("after linked: %s", s1);
    return 0; 
}








