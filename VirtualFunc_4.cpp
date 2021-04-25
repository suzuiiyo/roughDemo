//
// Created by yanGw on 2021/3/10.
//

#include <iostream>
using namespace std;

class Base
{
public:
    virtual void Add(){
        cout << "Base Virtual Add()!" << "\n";
    }

    virtual void Sub(){
        cout << "Base Virtual Sub()!" << "\n";
    }

    virtual void Div(){
        cout << "Base Virtual Div()!" << "\n";
    }
};

class Derive : public Base
{
public:
    //定义Derived类的Sub函数，与父类Base的Sub不同
    virtual void Sub(){
        cout << "Derive Virtual Sub()!" << "\n";
    }
};

int main()
{
    Base* b = new Base();
    b->Add();
    Base* d = new Derive();
    d->Add();
    d->Sub();
    return 0;
}