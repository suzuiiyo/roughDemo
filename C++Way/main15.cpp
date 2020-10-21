
#include <iostream>
using namespace std;

int main(){     
    auto f=3.14;                        //double
    auto s("hello");                    //const char*
    auto z = new auto(9);               //int*
    auto x1 = 5, x2 = 5.0, x3 ='r';     //错误，必须是初始化同一类型

}