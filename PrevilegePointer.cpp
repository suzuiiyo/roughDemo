//
// Created by yanGw on 2020/10/31.
//

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>

using namespace std;

class A {
public:
    A(int a, char b, float c);

private:
    int m_a;
    char m_b;
    float m_c;
};

A::A(int a, char b, float c) : m_a(a), m_b(b), m_c(c) {}

void test01() {
    A obj(10, '@', 30.5f);
    //int a = obj.m_a;          //Compile Error
    int x = *(int *) (uintptr_t) &obj;    //访问第一个变量
    char y = *((char *) ((uintptr_t) &obj + sizeof(int)));    //访问第二个变量,将第一个变量的地址转换成int格式， +第一个数据的长度sizeof(int)
    float z = *((float *) ((uintptr_t) &obj + sizeof(int) + sizeof(int)));  //访问第三个变量， 将第一个变量的地址转换为int格式， +第一个数据的长度sizeof(int)
    //+第二个数据长度sizeof(int)(之所以不是sizeof(char),是因为内存对齐）
    cout << x << endl;
    cout << y << endl;
    cout << z << endl;
    cout << endl;

    A *p = new A(40, 'A', 60.8f);
    //int b = p->m_b;  //Compile Error
    x = *(int *) (uintptr_t) p;
    y = *((char *) ((uintptr_t) p + sizeof(int)));
    z = *((float *) ((uintptr_t) p + sizeof(int) + sizeof(int)));
    cout << x << endl;
    cout << y << endl;
    cout << z << endl;
}

class B {
public:
    B(int aa, char bb, double cc, int dd);

private:
    int m_aa;
    char m_bb;
    double m_cc;
    int m_dd;
};

B::B(int aa, char bb, double cc, int dd) : m_aa(aa), m_bb(bb), m_cc(cc), m_dd(dd) {}

void test02() {
    B objb(11, 'C', 99.999, 66);
    int x = *(int *) (uintptr_t) &objb;    //访问第一个变量
    char y = *((char *) ((uintptr_t) &objb + sizeof(int)));  //访问第二个变量
    double z = *((double *) ((uintptr_t) &objb + sizeof(int) +
                             sizeof(int)));   //访问第三个变量   注意：char 占sizeof(int) 4个字节--内存对齐
    int xz = *(int *) ((uintptr_t) &objb + sizeof(int) + sizeof(int) + sizeof(double));   //访问第四个变量
    cout << x << endl;
    cout << y << endl;
    cout << z << endl;
    cout << xz << endl;

    cout << endl;

    B *pb = new B(22, 'D', 88.888, 55);

    x = *(int *) (uintptr_t) pb;
    y = *((char *) ((uintptr_t) pb + sizeof(int)));
    z = *((double *) ((uintptr_t) pb + sizeof(int) + sizeof(int)));  //访问第三个变量  注意: char 占sizeof (int) 4个字节 -- 内存对齐
    xz = *(int *) ((uintptr_t) pb + sizeof(int) + sizeof(int) + sizeof(double));   //访问第四个变量
    cout << x << endl;
    cout << y << endl;
    cout << z << endl;
    cout << xz << endl;
}

int main() {
    cout << "===test01===" << endl;
    test01();
    cout << endl;
    cout << "===test02===" << endl;
    test02();

    cout << endl;
    system("pause");
    return EXIT_SUCCESS;
}