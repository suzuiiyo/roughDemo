#include <iostream>

void func(void);

static int count = 10;  /* 全局变量 */

int main(){
    while(count--){
        func();
    }
    return 0;
}

//函数定义
void func(void){
    static int i =5; //局部j静态变量
    i++;
    std::cout << "变量 i 为" << i;
    std::cout << ", 变量count为 "  << count << std::endl;

}