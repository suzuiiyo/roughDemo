#include<stdio.h>

void debug_arg(unsigned int num, ...)
{
    unsigned int i = 0;
    unsigned int *addr = &num;
    for(i=0; i<=num; i++)
    {
        /* *(addr + i)从左往右依次取出传递进来的参数，类似于出栈过程*/
        printf("i=%d, value=%d\r\n", i, *(addr + i));
    }
}

int main(void)
{
    debug_arg(3, 66, 88, 666);
    return 0;
}