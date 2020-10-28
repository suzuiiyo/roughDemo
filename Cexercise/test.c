#include<stdio.h>

void func1(void);
static int count=10;   //全局变量 - static是默认的

int main()
{
    while (count--){
        func1();
    }
    return 0;
}

void func1(void)
{
    int thingy=5;
    thingy++;
    printf("thingy is %d, count is %d\n", thingy, count);
}