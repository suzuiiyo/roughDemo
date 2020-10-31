//
// Created by yanGw on 2020/10/31.
//

#include<iostream>
#include<string>

using namespace std;
//间接基类A
class A{
public:
    void seta(int a);
    void show();
protected:
    int m_a;
};

void A::seta(int a){
    m_a =a;
}

void A::show(){
    cout<<m_a<<endl;
}

//直接基类B
class B:virtual public A{   //虚继承
public:
    void setb(int b);
    void show();

protected:
    int m_b;
};

void B::show(){
    cout<<m_b<<endl;
}

void B::setb(int b) {
    m_b = b;
}

//直接基类C
class C: virtual public A{  //虚继承
public:
    void setc(int c);
    void show();

protected:
    int m_c;
};

void C::setc(int c){
    m_c = c;
}

void C::show(){
    cout<<m_c<<endl;
}

//派生类D
class D: public B, public C{
public:
    void stea(int a){m_a = a;}   //正确
    void steb(int b){m_b = b;}   //正确
    void stec(int c){m_c = c;}   //正确
    void sted(int d){m_d = d;}   //正确

private:
    int m_d;
};

int main(){
    D d;
    d.seta(11);
    d.setb(22);
    d.setc(33);

    d.A::show();
    d.B::show();
    d.C::show();
    return 0;
}