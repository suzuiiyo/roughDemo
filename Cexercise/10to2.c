#include<stdio.h>

int main()
{
    long n, binary=0;
    int remainder, flag=0;
    printf("请输入一个十进制数: ");
    scanf("%ld", &n);

    while(n>0)
    {
        remainder = n%2;
        n /= 2;
        binary += remainder * power(flag);
        flag++;
    }
    printf("输入数字的二进制形式为:%d", binary);  
}

int power(int i)
{
    int result=1;
    while(i>0)
    {
        result *= 10;
        --i;
    }
    return result;
}


