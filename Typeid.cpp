//
// Created by yanGw on 2020/11/5.
//
#include<iostream>

class A{
private:
    int a;
};

class B: public A{
public:
    virtual void f(){std::cout<<"HelloWorld\n";}

private:
    int b;
};

class C: public B{
public:
    virtual void f(){
        std::cout << "HelloWorld\n";
    }

private:
    int c;
};

class D: public A{
public:
    virtual void f(){
        std::cout<<"HelloWorld--\n";
    }

private:
    int d;
};

int main(){
    int a = 2;
    std::cout<<typeid(a).name()<<std::endl;
    A objA;
    //打印出class A
    std::cout<< typeid(objA).name()<<std::endl;
    B objB;
    std::cout << typeid(objB).name()<<std::endl;
    C objC;
    std::cout << typeid(objC).name()<<std::endl;

    B *ptrB =new C();
    std::cout<<typeid(*ptrB).name()<<std::endl;

    A *ptrA = new D();
    std::cout<<typeid(*ptrA).name()<<std::endl;

    return 0;
}
