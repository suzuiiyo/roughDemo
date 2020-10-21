#include <iostream>
#include <string>

using namespace std;

int main(){
    String str1 = "Hello";
    String str2 = "World";
    String str3;
    int len;

    //复制 str1到str3
    str3 = str1;
    cout << "str3 : " << str3 << endl;

    //连接str1和str2
    str3 = str1 + str2;
    cout << "str1 + str2 : " << str3 << endl;

    //连接后,str3的总长度
    len = str3.size();
    cout << "str3.size() : " << len << endl;

    return 0;
}