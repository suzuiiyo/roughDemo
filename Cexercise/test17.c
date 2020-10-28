#include<stdio.h>

int main()
{
    int sum=0;
    int num=1;
    int sum2=0;
    int num2=2;
    while(num<=100){
        sum+=num;
        num+=2;
    }
    printf("奇数和为：%d\n", sum);

    while(num2<=100){
        sum2+=num2;
        num2+=2;
    }
    printf("偶数和为：%d\n", sum2);
}