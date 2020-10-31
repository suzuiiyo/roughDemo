//
// Created by yanGw on 2020/10/30.
//

#include<iostream>
#include<string>

using namespace std;

class Base{
public:
    void func();
    void func(int);
};

void Base::func(){
    cout << "Base::func()" << endl;
}

void Base::func(int a){
    cout << "Base::func(int)"<<endl;
}

class Derived: public Base{
public:
    void func(string);
    void func(bool);
};

void Derived::func(string str){
    cout << "Derived:func(string)"<<endl;
}

void Derived::func(bool is){
    cout << "Derived::func(bool)"<<endl;
}

int main(){
    Derived d;
    d.func("www.pornhun.com");
    d.func(true);

    d.func(10);
    d.Base::func();
    d.Base::func(100);

    return 0;
}