//
// Created by yanGw on 2020/10/30.
//

#include<iostream>
#include<string>

using namespace std;

class BaseA {
public:
    BaseA(int a, int b);

    ~BaseA();

protected:
    int m_a;
    int m_b;
};

BaseA::BaseA(int a, int b) {
    m_a = a;
    m_b = b;
    cout << "BaseA constructor" << endl;
}

BaseA::~BaseA() {
    cout << "BaseA destructor" << endl;
}

class BaseB {
public:
    BaseB(int c, int d);

    ~BaseB();

protected:
    int m_c;
    int m_d;
};

BaseB::BaseB(int c, int d) {
    m_c = c;
    m_d = d;
    cout << "BaseB constructor" << endl;
}

BaseB::~BaseB() {
    cout << "BaseB destructor" << endl;
}

class Derived : public BaseA, public BaseB {
public:
    Derived(int a, int b, int c, int d, int e);

    ~Derived();

    void show();

    void show(int a);

private:
    int m_e;
};

Derived::Derived(int a, int b, int c, int d, int e) : BaseB(a, b), BaseA(c, d) {
    m_e = e;
    cout << "Derived constructor" << endl;
}

Derived::~Derived() {
    cout << "Derived destructor" << endl;
}

void Derived::show() {
    cout << m_a << "," << m_b << "," << m_c << "," << m_d << "," << m_e << endl;
}

void Derived::show(int a) {
    //成员函数才可以访问类的private属性, 类对象不能访问本类的private方法和属性，这一点跟java区别很大
    a = m_e;
    cout << "a = " << a << endl;
}

int main() {
    //构造函数没有给a, b, c, d初始化,所以打印出来的值很奇怪
    Derived obj(1, 2, 3, 4, 199);
    obj.show();

    int a = 12;
    cout << "a = " << a << endl;
    obj.show(a);

    return 0;
}