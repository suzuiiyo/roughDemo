//
// Created by yanGw on 2020/11/5.
//


#include<iostream>

using namespace std;

class complex {
public:
    complex(double real = 0.0, double imag = 0.0) : m_real(real), m_imag(imag) {}

public:
    friend complex operator+(const complex &A, const complex &B);

    friend complex operator-(const complex &A, const complex &B);

    friend complex operator*(const complex &A, const complex &B);

    friend complex operator/(const complex &A, const complex &B);

    friend istream &operator>>(istream &in, complex &A);

    friend ostream &operator<<(ostream &out, complex &A);

private:
    double m_real;   //实部
    double m_imag;   //虚部
};

complex operator+(const complex &A, const complex &B) {
    complex C;
    C.m_real = A.m_real + B.m_real;
    C.m_imag = A.m_imag + B.m_imag;

    return C;
}

complex operator-(const complex &A, const complex &B) {
    complex C;
    C.m_real = A.m_real - B.m_real;
    C.m_imag = A.m_imag - B.m_imag;

    return C;
}

complex operator*(const complex &A, const complex &B) {
    complex C;
    C.m_real = A.m_real * B.m_real - A.m_imag * B.m_imag;
    C.m_imag = A.m_real * B.m_imag + A.m_imag * B.m_real;

    return C;
}

complex operator/(const complex &A, const complex &B) {
    complex C;
    double square = A.m_real * A.m_real + A.m_imag * A.m_imag;
    C.m_real = (A.m_real * B.m_real + A.m_imag * B.m_imag) / square;
    C.m_imag = (A.m_imag * B.m_real - A.m_real * B.m_imag) / square;

    return C;
}

//重载输入运算符
istream &operator>>(istream &in, complex &A) {
    in >> A.m_real >> A.m_imag;
    return in;
}

//重载输出运算符
ostream &operator<<(ostream &out, complex &A) {
    out << A.m_real << " + " << A.m_imag << "i";
    return out;
}

int main() {
    complex c1, c2, c3;
    cout<<"请分别输入c1和c2两个虚数的实部和虚部:"<<endl;
    cin >> c1 >> c2;

    c3 = c1 + c2;
    cout << "c1 + c2 = " << c3 << endl;

    c3 = c1 - c2;
    cout << "c1 - c2 =  " << c3 << endl;

    c3 = c1 * c2;
    cout << "c1 * c2 = " << c3 << endl;

    c3 = c1 / c2;
    cout << "c1 / c2 = " << c3 << endl;

    return 0;
}