#include<stdio.h>

int x;
int y;
int addtwonum(){
    //函数内声明变量 x和y为外部变量
    extern int x;
    extern int y;
    //给外部变量(全局变量)x 和 y赋值
    x = 1;
    y = 2;
    return x + y;
}

int main(){
    int result;
    //调用函数 addtwonum
    result = addtwonum();

    printf("result 为: %d", result);
    return 0;
}