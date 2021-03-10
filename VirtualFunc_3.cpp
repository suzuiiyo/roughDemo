//
// Created by yanGw on 2021/3/10.
//

#include<iostream>
using namespace std;

class Base
{
public:
    virtual void Add()
    {
        cout << "Base Virtual Add()!" << "\n";
    }

    virtual void Sub()
    {
        cout << "Base Virtual Sub()!" << "\n";
    }

    virtual void Div()
    {
        cout << "Base Virtual Div()!" << "\n";
    }

};

int main()
{
    Base* b = new Base();
    b->Add();
    b->Sub();
    b->Div();
    return 0;
}
