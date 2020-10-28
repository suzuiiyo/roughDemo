#include<iostream>
#include<string>

using namespace std;

void Func1(int x){
    x += 10;
}

void Func2(int *x){
    *x += 10;
}

void Func3(int &x){
    x += 10;
}

int main(){
    /*int a = 99;
    int &r = a;
    cout << a << ", " << r << endl;
    cout << &a << ", " << &r << endl;*/

    int a = 7, b = 7, c = 7;
    Func1(a);
    Func2(&b);
    Func3(c);

    cout << "a = " << a << endl
         << "b = " << b << endl
         << "c = " << c << endl;

    return 0;
}
