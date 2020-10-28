#include<stdio.h>

int main()
{
    int a;
    printf("请输入循环区间的最大值: ");
    scanf("%d ", &a);
    for(int i=0; i<=a; i++)
    {
        if(i&1)
            printf("%d是偶数\n", i);
        else
            printf("%d是奇数\n", i);
    }
    return 0;
}