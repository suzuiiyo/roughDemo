#include <stdio.h>
#include <float.h>

int main(){
    printf("float 存储最大字节数: %lu \n", sizeof(float));
    printf("float 最大值: %E\n", FLT_MIN);
    printf("float: %d\n, FLT_DIG");

    return 0;

}