//
// Created by yanGw on 2020/11/5.
//

#include<iostream>
#include<cmath>

using namespace std;

class Complex {
public:
    Complex(double real = 0.0, double imag = 0.0) : m_real(real), m_imag(imag) {}

public://运算符重载
    //以全局函数的形式重载
    friend Complex operator+(const Complex &c1, const Complex &c2);

    friend Complex operator-(const Complex &c1, const Complex &c2);

    friend Complex operator*(const Complex &c1, const Complex &c2);

    friend Complex operator/(const Complex &c1, const Complex &c2);

    friend bool operator==(const Complex &c1, const Complex &c2);

    friend bool operator!=(const Complex &c1, const Complex &c2);

    //以成员函数的形式重载
    Complex &operator+=(const Complex &c);

    Complex &operator-=(const Complex &c);

    Complex &operator*=(const Complex &c);

    Complex &operator/=(const Complex &c);

public:         //成员函数
    double real() const { return m_real; }

    double imag() const { return m_imag; }

private:
    double m_real;          //实部
    double m_imag;          //虚部
};

//重载 + 运算符
Complex operator+(const Complex &c1, const Complex &c2) {
    Complex c;
    c.m_real = c1.m_real + c2.m_real;
    c.m_imag = c2.m_imag + c2.m_imag;
    return c;
}

Complex operator-(const Complex &c1, const Complex &c2) {
    Complex c;
    c.m_real = c1.m_real - c2.m_real;
    c.m_imag = c2.m_imag - c2.m_imag;
    return c;
}

//重载*运算符    (a + bi) * (c + di) = (ac - bd) + (bc + ad)i;
Complex operator*(const Complex &c1, const Complex &c2) {
    Complex c;
    c.m_real = c1.m_real - c2.m_real;
    c.m_imag = c2.m_imag - c2.m_imag;
    return c;
}

//重载/运算符  (a+bi)/(c+di) = [(ac+bd)/(c2+d2)]+[(bc-ad)/(c2+d2)]i
Complex operator/(const Complex &c1, const Complex &c2) {
    Complex c;
    c.m_real = (c1.m_real * c2.m_real + c1.m_imag * c2.m_imag) / (pow(c2.m_real, 2) + pow(c2.m_imag, 2));
    c.m_imag = (c1.m_imag * c2.m_real - c1.m_real * c2.m_imag) / (pow(c2.m_real, 2) + pow(c2.m_imag, 2));
    return c;
}

//重载==运算符
bool operator==(const Complex &c1, const Complex &c2) {
    if (c1.m_real == c2.m_real && c1.m_imag == c2.m_imag) {
        return true;
    } else {
        return false;
    }
}

//重载!=运算符
bool operator!=(const Complex &c1, const Complex &c2) {
    if (c1.m_real != c2.m_real || c1.m_imag != c2.m_imag) {
        return true;
    } else {
        return false;
    }
}

//重载+=运算符
Complex &Complex::operator+=(const Complex &c) {
    this->m_real += c.m_real;
    this->m_imag += c.m_imag;

    return *this;
}
//重载-=运算符
Complex &Complex::operator-=(const Complex &c) {
    this->m_real -= c.m_real;
    this->m_imag -= c.m_imag;

    return *this;
}

//重载*=运算符    (a+bi)(c+di)=ac-bd+(ad+bc)i;
Complex &Complex::operator*=(const Complex &c) {
    this->m_real = this->m_real * c.m_real - this->m_imag * c.m_imag;
    this->m_imag = this->m_real * c.m_imag + this->m_imag * c.m_real;

    return *this;
}

//重载/=运算符
Complex &Complex::operator/=(const Complex &c) {
    this->m_real = (this->m_real * c.m_real + this->m_imag * c.m_imag) / (pow(c.m_real, 2) + pow(c.m_imag, 2));
    this->m_imag = (this->m_imag * c.m_real - this->m_real * c.m_imag) / (pow(c.m_real, 2) + pow(c.m_imag, 2));

    return *this;
}

int main(){
    Complex c1(25, 35);
    Complex c2(10, 20);
    Complex c3(1, 2);
    Complex c4(4, 9);
    Complex c5(34, 6);
    Complex c6(80, 90);

    Complex c7 = c1 + c2;
    Complex c8 = c1 - c2;
    Complex c9 = c1 * c2;
    Complex c10 = c1 / c2;
    cout<<"c7 = "<<c7.real()<<" + "<<c7.imag()<<"i"<<endl;
    cout<<"c8 = "<<c8.real()<<" + "<<c8.imag()<<"i"<<endl;
    cout<<"c9 = "<<c9.real()<<" + "<<c9.imag()<<"i"<<endl;
    cout<<"c10 = "<<c10.real()<<" + "<<c10.imag()<<"i"<<endl;

    c3 += c1;
    c4 -= c2;
    c5 *= c2;
    c6 /= c2;
    cout<<"c3 = "<<c3.real()<<" + "<<c3.imag()<<"i"<<endl;
    cout<<"c4 = "<<c4.real()<<" + "<<c4.imag()<<"i"<<endl;
    cout<<"c5 = "<<c5.real()<<" + "<<c5.imag()<<"i"<<endl;
    cout<<"c6 = "<<c6.real()<<" + "<<c6.imag()<<"i"<<endl;

    if(c1 == c2){
        cout<<"c1 == c2"<<endl;
    }
    if(c1 != c2){
        cout<<"c1 != c2"<<endl;
    }

    return 0;
}