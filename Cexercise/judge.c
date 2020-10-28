#include<stdio.h>

int main()
{
    int a;
    printf("请输入一个正整数: ");
    scanf("%d", &a);

    if(a%2==0)
        printf("%d是偶数\n", a);
    else
        printf("%d是奇书\n", a);

    return 0;
}