#include <iostream>

using namespace std;

//全局变量声明
int g = 20;
int fun1(int a, int b){
    g = a + b;
    cout<<"被改变的全局变量为: "<<g<<endl;
    return 0;
}

int fun2(){
    cout<<"此时的全局变量为: "<<g<<endl;
    return 0;
}

int main(){
    fun2;
    fun1(10, 20);
    fun2();
    return 0;
}