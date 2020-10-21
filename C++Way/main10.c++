#include <iostream>
using namespace std;

//全局变量声明
int g = 99;

//函数声明
int func();

int main()
{
    //局部变量声明
    int g = 10;
    //cout << g;
    int kk = func();
    cout << kk;
    return 0;
}

//函数定义
int func(){
    return g;
}