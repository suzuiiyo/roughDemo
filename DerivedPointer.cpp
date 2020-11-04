//
// Created by yanGw on 2020/11/2.
//

#include <iostream>

using namespace std;

//基类A
class A {
public:
    A(int a);

    void display();

    int m_a;
};

A::A(int a) : m_a(a) {}

void A::display() {
    cout << "Class A: m_a = " << m_a << endl;
}

class B : public A {
public:
    B(int a, int b);

    void display();

protected:
    int m_b;
};

B::B(int a, int b) : A(a), m_b(b) {}

void B::display() {
    cout << "Class B: m_a = " << m_a << ", m_b = " << m_b << endl;
}

//基类C
class C : public A {
public:
    C(int a, int c);

    void display();

protected:
    int m_c;
};

C::C(int a, int c) : A(a), m_c(c) {}

void C::display() {
    cout << "Class C: m_a = " << m_a << ", m_c" << m_c << endl;
}

//最终派生类
class D : public B, public C {
public:
    D(int a, int b, int c, int d);

public:
    void display();

private:
    int m_d;
};

D::D(int a, int b, int c, int d) : B(a, b), C(a, c), m_d(d) {}

void D::display() {
    cout << "Class D: m_a = " << B::m_a << ", m_b = " << m_b << ", m_c" << m_c << ", m_d" << m_d << endl;
}

int main() {
    A *pa = new A(1);
    B *pb = new B(2, 20);
    C *pc = new C(3, 30);
    D *pd = new D(4, 40, 400, 4000);

    D d(4, 40, 400, 4000);
    //A &ra = d;
    B &rb = d;
    C &rc = d;

    cout << "派生类引用赋值给基类引用: " << endl;
    //ra.display();
    rb.display();
    rc.display();

    cout << "_______________" << endl;

    cout << "派生类指针赋值给基类指针: " << endl;
    //pa = pd;
    pa->display();

    pb = pd;
    pb->display();

    pc = pd;
    pc->display();

    cout << "_______________" << endl;
    cout << "指针赋值地址: " << endl;
    cout << "pa=" << pa << endl;
    cout << "pb=" << pb << endl;
    cout << "pc=" << pc << endl;
    cout << "pd=" << pd << endl;

    cout << "\n引用赋值地址: " << endl;
    //cout << "ra=" << &ra << endl;
    cout << "rb=" << &rb << endl;
    cout << "rc=" << &rc << endl;
    cout << "d=" << &d << endl;
    return 0;
}