//
// Created by yanGw on 2020/10/31.
//

//间接基类A
class A{
public:
protected:
    int m_a;
};

//直接基类B
class B: public A{
public:
protected:
    int m_b;
};

//直接基类C
class C: public A{
public:
protected:
    int m_c;
};

//派生类D
class D: public B, public C{
public:
    void seta(int a){
        //m_a=a;          //命名冲突
        B::m_a=a;
    }

    void setb(int b){
        m_b=b;
    }

    void setc(int c){
        m_c = c;
    }

    void setd(int d){
        m_d = d;
    }

private:
    int m_d;
};

int main(){
    D d;
    return 0;
}