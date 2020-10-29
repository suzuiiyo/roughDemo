#include<iostream>
#include<string>

using namespace std;

class Base{
    public:
        void func();
        void func(int);
};

void Base::func(){
    cout << "Base::func()" << endl;
}

void Base::func(int a){
    cout << "Base::func(int)" << endl;
}

//派生类Derived
class Derived: public Base{
    public:
        void func(string);
        void func(bool);
        void func(float);
};

void Derived::func(string str){
    cout << "Derived:func(string)" << endl;
}

void Derived::func(bool is){
    cout << "Derived::func(bool)" << endl;
}

void Derived::func(float a){
    cout << "Derived::func(float)" << endl;
}

int main(){
    Derived d;
    d.func("www.pornhub.com");
    d.func(true);
    //d.func();        子类没继承func()被覆盖了
    d.func(10.56f);
    d.Base::func();
    d.Base::func(100);

    return 0;
}