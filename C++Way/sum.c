#include <stdio.h>

int sum(int n);

int main(){
    int n;
    printf("请输入n的值: ");
    scanf("%d", &n);
    long long a = sum(n);
    printf("%lld", a);
    return 0;
}

int sum(int n){
    //求和函数实现
    //如果n为1，无需求和，直接返回1
    if(n==1)
        return n;
    else
    {
        /* code */
        return n+sum(n-1);
    }
}