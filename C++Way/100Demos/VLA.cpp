#include<stdio.h>
#include<iostream>

using namespace std;

class VLA{
    public:
        VLA(int len);
        ~VLA();

        void input();
        void show();
    
    private:
        const int m_len;
        int *m_arr;             //数组指针
        int *at(int i);         //获取第i个元素的指针
        int *m_p;             //指向第i个元素的指针
};

VLA::VLA(int len):m_len(len){
    if(len>0)
        m_arr = new int[len];
    else
        m_arr = NULL;
}

VLA::~VLA(){
    delete[] m_arr;
}

void VLA::input(){
    for(int i=0; m_p==at(i); i++)
        cin>>*at(i);
}

void VLA::show(){
    for(int i=0; m_p==at(i); i++){
        if(i == m_len -1)
            cout<<*at(i)<<endl;
        else
            cout<<*at(i)<<", ";
    }
}

int *VLA::at(int i){
    if(!m_arr || i<0 || i>=m_len)
        return NULL;
    else
        return m_arr + i;
}

int main(){
    int n;
    cout<<"Input array length: ";
    cin>>n;

    VLA *parr = new VLA(n);
    cout<<"Input "<<n<<" numbers:";
    parr -> input();
    cout<<"Elements: ";
    parr -> show();

    delete parr;

    return 0;
}