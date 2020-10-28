#include<stdio.h>

int power(int i);

int main()
{
    long long n, decimal=0;
    int flag=0, remainder;
    printf("请输入一个二进制数: ");
    scanf("%ld", &n);

    while(n>0)
    {
        remainder = n%10;
        n /= 10;
        decimal += remainder*power(flag);
        flag++;
    }  
    printf("输入的二进制数的十进制形式是%d", decimal);
}

int power(int i)
{
    int result=1;
    while(i>0)
    {
        result *= 2;
        --i;
    }
    return result;
}