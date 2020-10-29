//
// Created by yangw on 2020/10/29.
//

#include<iostream>
#include<string>

using namespace std;

int main(){
    int a, b;
    int temp = 0;

    cout<<"请输入两个数字， 以空格隔开:"<<endl;
    cin>>a;
    cin>>b;
    cout<<"a = "<<a<<", b = "<<b<<endl;

    temp = a;
    a = b;
    b = temp;
    cout<<"a = "<<a<<", b = "<<b<<endl;
}