#include<stdio.h>

int power(int i);

int main()
{
    long n, octal=0;
    int remainder, flag=0;
    printf("请输入一个八进制数: ");
    scanf("%ld", &n);

    while(n>0)
    {
        remainder = n%8;
        n /= 8;
        octal += remainder * power(flag);
        flag++;
    }
    printf("输入数字的十进制形式为:%d", octal);  
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
