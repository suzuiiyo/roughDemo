#include<iostream>
#include<string>

using namespace std;

//包虚函数的类
class A{
    public:
        virtual void func1(){}

        virtual void func2(){}
};

//空类
class B{
};

//包含成员函数不包含成员变量的类
class C{
    void fun(){
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