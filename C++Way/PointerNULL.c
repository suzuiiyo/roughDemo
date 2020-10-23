#include <stdio.h>

int main(){
    char c[10];
    char *ptr;
    ptr = c;
    printf("ptr 的地址是 %p\n", ptr);

    int var = 20;   /* 实际变量的声明 此时的var这个变量是存在某个地址的， 地址对应某个内存单元，该单元中存储了数据20 */
    int *ip;   /*指针变量的声明 定义了一个指针即一个内存单元的指针变量 */
    ip = &var;  /*在指针变量中存储var的地址 就是将j地址值赋值给指针这个变量 */

    /*在指针变量中存储的地址  利用&符号直接输出了var所存储的数据的内存单元的地址*/
    printf("Address of var variable: %p\n", &var);

    /*在指针变量中存储的地址 ip代表的是这个赋值到的地址的值  所以输出的是地址值 */
    printf("Address stored in ip variable: %p\n", ip);

    /*使用指针访问值 *ip代表的是定义到这个内存单元之后，内存单元中所存储的数据的值也就j将20辅助给var中20的这个值  */
    printf("Value of *ip variable: %d\n", *ip);

    return 0;
}