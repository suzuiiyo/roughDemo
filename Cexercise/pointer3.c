#include<stdio.h>

const int MAX = 3;

int main()
{
    int var[] = {10, 100, 200};
    int i, *ptr;

    //指针中的数组地址
    ptr = &var[MAX-1];
    for(i=MAX; i>0; i--)
    {
        printf("存储地址:var[%d]=%x\n", i, &var[i]);
        printf("存储值:var[%d]=%d\n", i, *ptr);

        //移动到下一个位置
        ptr--;
        printf("%x\n", ptr);
    }
    return 0;
}

