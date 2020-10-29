#include <iostream>
#include <string>

using namespace std;
class A
{
public:
    void p()
    {
        cout << "a" << endl;
    }
};

class B : public A
{
public:
    void p()
    {
        cout << "b" << endl;
    }
};

int main()
{
    A *a = new A;
    //父类用指针访问子类对象的方法也是不可行的
    A *b = new B;
    B *b1 = new B;
    a->p();
    b->p();
    b1->p();
    delete a;
    delete b;
    delete b1;
}