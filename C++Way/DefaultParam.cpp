#include <iostream>
using namespace std;

//带默认参数的函数
void func(int n, float b=1.2, char c = '@'){
    cout<<n<<", "<<b<<", "<<c<<endl;
}

int main(){
    //为所有参数传值
    func(10, 3.5, '#');
    //为n, b传值，x相当于调用func(20， 9.8, '@')
    func(20, 9.8);
    //只为n传值x相当于调用func(30, 1.2, '@')
    func(30);

    return 0;
}