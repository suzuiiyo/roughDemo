//
// Created by yanGw on 2020/11/4.
//
#include<iostream>

class E {
public:
    virtual void func(int i = 0) {
        std::cout << "E::func()\t" << i << "\n";
    }
};

class F : public E {
public:
    virtual void func(int i = 1) {
        std::cout << "F::func()\t" << i << "\n";
    }
};

/*绝对不要重新定义一个继承而来的virtual函数的缺省参数值，
 因为缺省参数值都是静态绑定（为了执行效率），而virtual函数却是动态绑定*/
void test2() {
    F *pf = new F();
    E *pe = pf;
    pf->func();     //F::func() 1  正常，就该如此
    pe->func();     //F::func() 0  哇哦，这是什么情况,调用了子类的函数，却使用了基类中参数的默认值;
}

int main() {
    test2();
}