//
// Created by yanGw on 2020/11/5.
//

#include<iostream>

using namespace std;

class complex{
public:
    complex();
    complex(double real, double imag);

public:
    void display() const;
    //声明为友元函数
    friend complex operator+(const complex &A, const complex &B);

    private:
    double m_real;
    double m_imag;
};

complex operator+(const complex &A, const complex &B);

complex::complex():m_real(0.0), m_imag(0.0){}
complex::complex(double real, double imag): m_real(real), m_imag(imag){}

void complex::display() const{
    cout<<m_real<<"+"<<m_imag<<"i"<<endl;
}

//在全局范围内重载
complex operator+(const complex &A, const complex &B){
    complex C;
    C.m_real = A.m_real + B.m_real;
    C.m_imag = A.m_imag + B.m_imag;

    return C;
}

int main(){
    complex c1(4.3, 5.8);
    complex c2(2.4, 3.7);
    complex c3;
    c3 = c1 + c2;
    c3.display();

    return 0;
}
