//
// Created by yanGw on 2020/10/30.
//

#include<iostream>
#include<string>

using namespace std;

class Swap {
public:
    void show();

    void show(int a, int b);

    void swapPointer(int *a, int *b);

    void swapReference(int &a, int &b);

    void setValue(int a, int b);

private:
    int m_val1;
    int m_val2;
};

void Swap::show() {
    cout << "a = " << m_val1 << ", b = " << m_val2 << endl;
}

void Swap::show(int a, int b) {
    cout << "a = " << a << ", b = " << b << endl;
}

void Swap::swapPointer(int *a, int *b) {
    int temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
}

void Swap::swapReference(int &a, int &b) {
    int temp = 0;
    temp = a;
    a = b;
    b = temp;
}

void Swap::setValue(int a, int b) {
    m_val1 = a;
    m_val2 = b;
}

int main() {
    int a = 12, b = 78;
    Swap Swap{};
    cout<<"不调用交换方法: "<<endl;
    Swap.setValue(a, b);
    Swap.show();
    Swap.show(a, b);
    Swap.swapPointer(&a, &b);
    cout<<"\n调用swapPointer: "<<endl;
    Swap.show();
    Swap.show(a, b);
    Swap.swapReference(a, b);
    cout<<"\n调用swapReference: "<<endl;
    Swap.show();
    Swap.show(a, b);

    return 0;
}