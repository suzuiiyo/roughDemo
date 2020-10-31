//
// Created by yanGw on 2020/10/30.
//

#include<iostream>
#include<string>
using namespace std;

class A{
public:
    virtual void func1(){}

    virtual void func2(){}
};

class B{
};

class C {
    void func() {
    }
};

void Test1(){
    cout << sizeof(A) << endl;
    cout << sizeof(B) << endl;
    cout << sizeof(C) << endl;
}

int main(){
    Test1();
}