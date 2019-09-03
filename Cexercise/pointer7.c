#include<stdio.h>

int main()
{
    int var;
    int *ptr;
    int **pptr;

    var = 3000;

    //获取var的地址
    ptr = &var;
    //使用运算符&获取ptr的地址
    pptr = &ptr;

    //使用pptr获取值
    printf("Address of var is %x\n", &var);




    
    printf("Value of var = %d\n", var);
    printf("Address of ptr is %x\n", ptr);
    printf("Value available at *ptr = %d\n", *ptr);
    printf("Address of pptr is %x\n", pptr);
    printf("Value available at **ptr = %d\n", **pptr);
    
    return 0;
  }