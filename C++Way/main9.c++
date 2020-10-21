#include <iostream>
using namespace std;

int count = 1;  //全局变量

int fun(){
    static int count = 10; //在第一进入j这个函数的时候，变量count被初始化为10! j接着自减1， 以后每进入j该函数， count的值是上一次函数运行之后得值
    return count--; //就不会被再次初始化了，进行自减1的操作， 在static发明前，要达到同样的功能，则只能使用全局变量
}

//int count = 1
