#include<stdio.h>

int num;
int func(int num)
{
    if((num>0)&&(num&(num-1))==0)
    {
        printf("%d是2的整数幂", num);
    }

    else
    {
        printf("%d不是2的整数幂", num);
    }
    return((num>0)&&(num&(num-1))==0);
}

int main()
{
    printf("请输入要查询的整数\n");
    scanf("%d", &num);
    func(num);
}