#include <stdio.h>

int main(void)
{
    enum MONTH{A=1,B,C,D,F=10};    //注意B的值是在A加1，C是B加1....所以D你知道吧
    enum MONTH month=A;
    for(month=A;month<F;month++)
    printf("the value of month is :%d  ",month);
    return 0;
}