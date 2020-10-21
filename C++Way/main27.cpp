#include <iostream>
#include <cstring>

using namespace std;

int main(){
    char str1[11] = "Hello";
    char str2[11] = "World";
    char str3[11];
    int len;

    //复制str1到str2
    strcpy(str3, str1);
    cout << "strcpy( str3, str1) : " << str3 << endl;

    //连接 str1和str2
    strcat(str1, str2);
    cout << "strcat(str1, str2): " << str1 << endl;

    //连接后，str1的总长度
    len = strlen(str1);
    cout << "strlen(str1): " << len << endl;

    return 0;
}