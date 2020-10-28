#include<iostream>

using namespace std;

int &plus10(int &r){
    r += 10;
    return r;
}

//返回引用不要j局部变量否则程序结果得不到期望j结果
int &plus20(int &r){
    int m = r + 10;
    return r;
}

int main(){
    int num1 = 10;
    int num2 = plus10(num1);
    cout << num1 << " " << num2 << endl;

    //num3作为返回值在plus20
    int &num3 = plus20(num1);
    int &num4 = plus20(num3);
    cout << num3 << " " << num4 << endl;
    return 0;
}