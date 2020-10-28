#include<stdio.h>

int main()
{
    int num;
    printf("请输入一个整数: ");
    scanf("%d", &num);

    if(num&1)
        printf("%d是奇数", num);
    else
        printf("%d是偶数", num);    
}