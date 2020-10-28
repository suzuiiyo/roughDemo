#include<stdio.h>

int main()
{   
    int n;
    printf("请输入正整数n: ");
    scanf("%d", &n);
    for(int i =0; i<=n; i++)
        printf("%d, ", fabonaci(i));
}

int fabonaci(int n)
{
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    return fabonaci(n-1) + fabonaci(n-2);
}