#include<stdio.h>

int x;
int y;
int addtwonm()
{
    extern int x;
    extern int y;
    x = 1;
    y = 2;
    return x+y;
}

int main()
{
    int result;
    result = addtwonm();

    printf("result is£º%d\n", result);
    system("pause");
    return 0;
}

