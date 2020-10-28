#include<stdbool.h>
#include<stdio.h>

//计算n!, n的值在main中定义
int main(void)
{
    int n = 10; //计算叠乘数
    int sum = 1; //用来存放叠乘的结果
    bool flag = false; //叠乘标记

    int num = n; //循环次数
    while(!flag)
    {
        sum = sum * (num--);
        if( num==1 )
        {
            flag = true;
        }
    }
    printf("%d的叠乘值为 %d \n", n, sum);
    return 0;
}