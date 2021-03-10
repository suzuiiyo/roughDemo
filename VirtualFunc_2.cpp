//
// Created by yanGw on 2021/3/10.
//

/*
 * 这个例子是虚函数的一个典型应用，通过这个例子，也许你就对虚函数有了一些概念。它虚就虚在所谓"推迟联编"或者"动态联编"上，一个类函数的调用并不是在编译时刻被确定的，而是在运行时刻被确定的。由于编写代码的时候并不能确定被调用的是基类的函数还是哪个派生类的函数，所以被成为"虚"函数。
虚函数只能借助于指针或者引用来达到多态的效果。
 */
#include<iostream>
using namespace std;

class A
{
public:
    virtual void foo()
    {
        cout<<"A::foo() is called"<<endl;
    }
};

class B:public A
{
public:
    void foo()
    {
        cout<<"B::foo() is called"<<endl;
    }
};

int main(void)
{
    A *a = new B();
    a->foo();               //在这里，a虽然是指向A的指针，但是被调用的函数(foo)确是B的!
    return 0;
}